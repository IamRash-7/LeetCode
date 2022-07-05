// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
class Solution
{
	public:
	//Function to return list containing vertices in Topological order. 
	void dfs(int node, vector<int>adj[], vector<int> &vis, stack<int> &st)
	{
	    vis[node]=1;
	    for(auto ele:adj[node])
	    {
	        if(vis[ele]==0)
	            dfs(ele,adj,vis,st);
	    }
	    st.push(node);
	}
	
	vector<int> topoSort(int V, vector<int> adj[]) 
	{
	    // BFS
	    /*
	    vector<int> degree(V,0);
	    vector<int> res;
	    
	    for(int i=0;i<V;i++)
	    {
	        for(auto ele:adj[i])
	            degree[ele]++;
	    }
	    
	    queue<int> q;
	    for(int i=0;i<degree.size();i++)
	    {
	        if(degree[i]==0)
	            q.push(i);
	    }
	    
	    while(!q.empty())
	    {
	        int top = q.front();
	        q.pop();
	        res.push_back(top);
	        for(auto it : adj[top])
	        {
	            degree[it]--;
	            if(degree[it]==0)
	                q.push(it);
	        }
	        
	    }
	    return res;
	    */
	    
	    // DFS
	    
	    vector<int> vis(V,0);
	    stack<int> st;
	    for(int i=0;i<V;i++)
	    {
	        if(vis[i]==0)
	            dfs(i,adj,vis,st);
	    }
	    
	    vector<int> res;
	    while(!st.empty())
	    {
	        res.push_back(st.top());
	        st.pop();
	    }
	    
	    return res;
	}
};

// { Driver Code Starts.

/*  Function to check if elements returned by user
*   contains the elements in topological sorted form
*   V: number of vertices
*   *res: array containing elements in topological sorted form
*   adj[]: graph input
*/
int check(int V, vector <int> &res, vector<int> adj[]) {
    
    if(V!=res.size())
    return 0;
    
    vector<int> map(V, -1);
    for (int i = 0; i < V; i++) {
        map[res[i]] = i;
    }
    for (int i = 0; i < V; i++) {
        for (int v : adj[i]) {
            if (map[i] > map[v]) return 0;
        }
    }
    return 1;
}

int main() {
    int T;
    cin >> T;
    while (T--) {
        int N, E;
        cin >> E >> N;
        int u, v;

        vector<int> adj[N];

        for (int i = 0; i < E; i++) {
            cin >> u >> v;
            adj[u].push_back(v);
        }
        
        Solution obj;
        vector <int> res = obj.topoSort(N, adj);

        cout << check(N, res, adj) << endl;
    }
    
    return 0;
}  // } Driver Code Ends