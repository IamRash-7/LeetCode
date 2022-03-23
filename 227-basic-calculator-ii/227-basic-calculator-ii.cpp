class Solution {
public:
    int calculate(string s) {
        int n = s.size();
        stack<int> st;
        int curno = 0;
        char op = '+';
        for(int i=0;i<n;i++)
        {
            char curchar = s[i];
            if(isdigit(curchar))
            {
                curno = (curno * 10) + (curchar - '0');
            }
            if(!isdigit(curchar) && !iswspace(curchar) || i == n - 1)
            {
                if(op == '-')
                    st.push(-curno);
                else if(op == '+')
                    st.push(curno);
                else if(op == '*')
                {
                    int r1 = st.top();
                    st.pop();
                    st.push(r1*curno);
                }
                else if(op == '/')
                {
                    int r1 = st.top();
                    st.pop();
                    st.push(r1/curno);
                }
                
                op = curchar;
                curno = 0;
            }
        }
        
        int res = 0;
        while(st.size() != 0)
        {
            res += st.top();
            st.pop();
        }
        return res;
    }
};