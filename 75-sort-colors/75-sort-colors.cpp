class Solution {
public:
    void sortColors(vector<int>& nums) {
        int low = 0, mid=0,high=nums.size()-1;
        while(mid<=high)
        {
            if(nums[mid]==0)
            {
                swap(nums[mid],nums[low]);
                low++;
                mid++;
            }
            else if(nums[mid]==1)
                mid++;
            else
            {
                swap(nums[mid],nums[high]);
                high--;
            }
        }
        
        
        
        // int zer=0, one=0, two=0;
        // int j;
        // for(int i:nums)
        // {
        //     if(i==0)
        //         zer++;
        //     else if(i==1)
        //         one++;
        //     else
        //         two++;
        // }
        // for(j=0;j<zer;j++)
        //     nums[j]=0;
        // for(;j<zer+one;j++)
        //     nums[j]=1;
        // for(;j<zer+one+two;j++)
        //     nums[j]=2;
    }
};