// { Driver Code Starts
//Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


 // } Driver Code Ends
/*You are required to complete this function*/

class Solution{
    public:
    int maxLen(vector<int>&A, int n)
    {   
        // Your code here
        map<int,int> mp;
        mp[0] = 0;
        int maxlen = 0;
        int sum = 0;
        for(int i=0;i<A.size();i++)
        {
            sum += A[i];
            if(mp.find(sum)!=mp.end())
            {
                maxlen = max(maxlen,i+1 - mp[sum]);
                
            }
            else
            {
                mp[sum] = i+1;
            }
        }
        return maxlen;
    }
};


// { Driver Code Starts.

int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int m;
        cin>>m;
        vector<int> array1(m);
        for (int i = 0; i < m; ++i){
            cin>>array1[i];
        }
        Solution ob;
        cout<<ob.maxLen(array1,m)<<endl;
    }
    return 0; 
}


  // } Driver Code Ends