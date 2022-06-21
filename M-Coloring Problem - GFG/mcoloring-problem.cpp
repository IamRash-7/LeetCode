// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


 // } Driver Code Ends
// Function to determine if graph can be coloured with at most M colours such
// that no two adjacent vertices of graph are coloured with same colour.

bool issafe(int edge, vector<int>&res, int color, bool graph[101][101],int n)
{
    for(int i=0;i<n;i++)
    {
        if(graph[edge][i]==true && res[i]==color)
            return false;
    }
    return true;
}

bool recur(bool graph[101][101], int m,int n, int edge, vector<int>&res)
{
    if(edge==n)
        return true;
    for(int i=1;i<=m;i++)
    {
        if(issafe(edge,res,i,graph,n))
        {
            res[edge] = i;
            if(recur(graph,m,n,edge+1,res))
                return true;
            res[edge] = 0;
        }
    }
    return false;
}

bool graphColoring(bool graph[101][101], int m, int n) {
    // your code here
    vector<int> res(n,0);
    return recur(graph,m,n,0,res);
}



// { Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, m, e;
        cin >> n >> m >> e;
        int i;
        bool graph[101][101];
        for (i = 0; i < n; i++) {
            memset(graph[i], 0, sizeof(graph[i]));
        }
        for (i = 0; i < e; i++) {
            int a, b;
            cin >> a >> b;
            graph[a - 1][b - 1] = 1;
            graph[b - 1][a - 1] = 1;
        }
        cout << graphColoring(graph, m, n) << endl;
    }
    return 0;
}
  // } Driver Code Ends