class Solution {
public:
    int lastStoneWeight(vector<int>& st) {
        while(st.size()>=2)
        {
            sort(st.begin(),st.end());
            int a = st.back();
            st.pop_back();
            int b = st.back();
            st.pop_back();
            if(a-b != 0)
                st.push_back(a-b);
        }
        if(st.size()!=0)
            return st[0];
        return 0;
    }
};