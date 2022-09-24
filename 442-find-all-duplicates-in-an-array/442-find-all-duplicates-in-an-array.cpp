class Solution {
public:
    vector<int> findDuplicates(vector<int>& nums) {
        vector<int> res;
        int n = nums.size();
        for(int i=0;i<n;i++)
        {
            int index = nums[i];
            if(nums[abs(index)-1]<0)
                res.push_back(abs(index));
            nums[abs(index)-1] = -nums[abs(index)-1];
        }
        return res;
    }
};