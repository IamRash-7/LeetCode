class Solution {
public:
    void sortColors(vector<int>& nums) {
        int one=0, two=0, zero=0;
        for(int i:nums)
        {
            if(i==0)
                zero++;
            else if(i==1)
                one++;
            else
                two++;
        }
        int i=0;
        for(i=0;i<zero;i++)
            nums[i]=0;
        for(i=zero;i<zero+one;i++)
            nums[i]=1;
        for(i=zero+one;i<zero+one+two;i++)
            nums[i]=2;
    }
};