class Solution {
public:
    int trap(vector<int>& height) {
        int l = 0;
        int leftmax = 0;
        int r = height.size()-1;
        int rightmax = 0;
        int cnt = 0;
        while(l<=r)
        {
            if(height[l]<=height[r])
            {
                if(height[l]>=leftmax)
                    leftmax = height[l];
                else
                    cnt += leftmax - height[l];
                
                l++;
            }
            else
            {
                if(height[r]>=rightmax)
                    rightmax = height[r];
                else
                    cnt += rightmax - height[r];
                
                r--;
            }
        }
        return cnt;
    }
};