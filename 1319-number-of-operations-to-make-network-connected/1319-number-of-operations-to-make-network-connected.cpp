class Solution {
public:
    
    void dfs(int node, vector<int>adj[], vector<int>&visited)
    {
        visited[node] = 1;
        for(auto it : adj[node])
        {
            if(visited[it]==0)
                dfs(it,adj,visited);
        }
    }
    
    
    int makeConnected(int n, vector<vector<int>>& connections) {
        int consize = connections.size();
        if(consize< n-1)
            return -1;
        
        vector<int> adj[n];
        for(auto i:connections)
        {
            adj[i[0]].push_back(i[1]);
            adj[i[1]].push_back(i[0]);
        }
        
        vector<int> visited(n,0);
        int disc=0;
        for(int i=0;i<n;i++)
        {
            if(visited[i]==0)
            {
                dfs(i,adj,visited);
                disc++;
            }
        }
        
        return disc-1;
    }
};