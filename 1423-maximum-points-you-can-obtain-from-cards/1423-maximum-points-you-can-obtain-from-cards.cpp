class Solution {
public:
    int maxScore(vector<int>& cardPoints, int k) {
        int n = cardPoints.size();
        int ans=0;
        for(int i=0;i<k;i++)
        {
            ans += cardPoints[i];
        }
        int best = ans;
        for(int i=k-1, j=n-1;i>=0;i--,j--)
        {
            ans += cardPoints[j]-cardPoints[i];
            best = max(best,ans);
        }
        return best;
    }
};