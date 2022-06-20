class Solution {
public:
    string getPermutation(int n, int k) {
        vector<int> res;
        int fact=1;
        for(int i=1;i<n;i++)
        {
            fact = fact*i;
            res.push_back(i);
        }
        res.push_back(n);
        k = k-1;
        string ans;
        while(res.size()>0)
        {
            ans = ans+ to_string(res[k/fact]);
            res.erase(res.begin()+k/fact);
            if(res.size()==0)
                break;
            k = k%fact;
            fact = fact/res.size();
        }
        return ans;
    }
};