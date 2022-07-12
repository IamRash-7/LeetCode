// { Driver Code Starts
//Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
//User function Template for C++

class Solution {
  public:
    int maxCoins(int A[], int B[], int T, int N) {
        vector<pair<int, int>> v;
        for (int i = 0; i < N; i++) 
            v.push_back({B[i], A[i]});
            
        sort(v.begin(), v.end());
        int ans = 0;
        for (int i = N - 1; i >= 0; i--) 
        {
            if (T == 0)
                break;
            if (v[i].second <= T) 
            {
                ans += v[i].first*v[i].second;
                T -= v[i].second;
            }
            else {
                ans += T*v[i].first;
                T = 0;
            }
        }
        return ans;
    }
};

// { Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int T,N;
        cin>>T>>N;
        
        int A[N], B[N];
        
        for(int i=0; i<N; i++)
            cin>>A[i];
        for(int i=0; i<N; i++)
            cin>>B[i];

        Solution ob;
        cout << ob.maxCoins(A,B,T,N) << endl;
    }
    return 0;
}  // } Driver Code Ends