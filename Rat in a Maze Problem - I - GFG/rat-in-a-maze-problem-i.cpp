// { Driver Code Starts
// Initial template for C++

#include <bits/stdc++.h>
using namespace std;


 // } Driver Code Ends
// User function template for C++

class Solution{
    public:
    
    void recur(vector<vector<int>> &m, int n, int row, int col, string s, vector<string> &ans)
    {
        if(row == n-1 && col==n-1)
            {
                ans.push_back(s);
                return;
            }
        if(row+1 <n && m[row+1][col]==1)
        {
            m[row][col] = -1;
            recur(m,n,row+1,col,s+'D',ans);
            m[row][col] = 1;
        }
        if(row-1 >= 0 && m[row-1][col]==1)
        {

            m[row][col] = -1;
            recur(m,n,row-1,col,s+'U',ans);
            m[row][col] = 1;
        }
        if(col+1 <n && m[row][col+1]==1)
        {
            m[row][col] = -1;
            recur(m,n,row,col+1, s+'R',ans);
            m[row][col] = 1;
        }
        if(col-1 <n && m[row][col-1]==1)
        {
            m[row][col] = -1;
            recur(m,n,row,col-1, s+'L',ans);
            m[row][col] = 1;
        }
    }
    
    vector<string> findPath(vector<vector<int>> &m, int n) {
        // Your code goes here
        vector<string> ans;
        string s;
        if(m[0][0])
            recur(m,n,0,0,s,ans);
        return ans;
    }
};

    


// { Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<vector<int>> m(n, vector<int> (n,0));
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                cin >> m[i][j];
            }
        }
        Solution obj;
        vector<string> result = obj.findPath(m, n);
        sort(result.begin(), result.end());
        if (result.size() == 0)
            cout << -1;
        else
            for (int i = 0; i < result.size(); i++) cout << result[i] << " ";
        cout << endl;
    }
    return 0;
}  // } Driver Code Ends