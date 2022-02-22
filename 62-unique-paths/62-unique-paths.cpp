class Solution {
public:
    int uniquePaths(int m, int n) {
        vector<vector<int>> dp(m+1,vector<int>(n+1,0));
        return recur(m,n,dp);
    }
    
    int recur(int m, int n, vector<vector<int>> &dp)
    {
        if(m==0 || n==0)
            return 0;
        if(m==1 || n==1)
            return 1;
        if(dp[m][n])
            return dp[m][n];
        
        dp[m][n] =  recur(m-1, n,dp) + recur(m,n-1,dp);
        return dp[m][n];
    }
};