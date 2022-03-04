class Solution {
public:
   static bool cmp(pair<int, int>& a,pair<int, int>& b)
    {
        return a.second > b.second;
    }
  
    vector<int> topKFrequent(vector<int>& nums, int k) {
        map <int,int> H;
        for(int i=0;i<nums.size();i++)
        {
            if(H[nums[i]])
                H[nums[i]]++;
            else
                H[nums[i]] = 1;
        }
        vector<pair<int, int> > A;
  
        for (auto& it : H) {
            A.push_back(it);
        }

        sort(A.begin(), A.end(), cmp);
        
        vector<int> ans;
        for(int i=0;i<k;i++)
        {
            ans.push_back(A[i].first);
        }
        return ans;
    }
};