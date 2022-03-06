class Solution {
public:
    int kthSmallest(vector<vector<int>>& matrix, int k) {
        priority_queue<int> h;
        int n = matrix.size();
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<n;j++)
            {
                h.push(matrix[i][j]);
                if(h.size() > k)
                    h.pop();
            }
        }
        return h.top();
    }
};