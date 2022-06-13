class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        int a = m+n-1;
        int b = m-1;
        int c = n-1;
        while(c>=0 && b>=0)
        {
            if(nums1[b]<nums2[c])
            {
                nums1[a--]=nums2[c--];
            }
            else
            {
                nums1[a] = nums1[b];
                b--;
                a--;
            }
        }
        while(c>=0)
            nums1[a--] = nums2[c--];
    }
};