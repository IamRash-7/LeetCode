class Solution {
public:
    bool canFinish(int n, vector<vector<int>>& prerequisites) {
        // BFS
        /*  
        vector<vector<int>> G(n);
        vector<int> degree(n, 0);
        queue<int> q;
        
        for (auto e : prerequisites)
        {
            // the path is from 1->0 (bi -> ai)
            G[e[1]].push_back(e[0]); // connect 1->0
            degree[e[0]]++; // indegree of 0 ++
        }
        
        for(int i = 0; i < n; ++i) 
        {
            // push indegree 0 elements
            if(degree[i]==0) 
                q.push(i);
        }
        int cnt=0;
        
        while(!q.empty())
        {
            cnt++;
            int node = q.front();
            q.pop();
            for(auto ele : G[node])
            {
                degree[ele]--;
                if(degree[ele]==0)
                    q.push(ele);
            }
        }
        
        return cnt==n;
        */
        
        // DFS
        vector<vector<int>> g(n);
        vector<bool> todo(n, false), visited(n, false);
        for (auto p : prerequisites) 
        {
            g[p[1]].push_back(p[0]);
        }
        
        for (int i = 0; i < n; i++) {
            if (visited[i]==false) 
            {
                if(iscyclic(g, todo, visited, i))
                    return false;
            }
        }
        return true;
    }
    
    bool iscyclic(vector<vector<int>>& g, vector<bool>& todo, vector<bool>& visited, int node)
    {
        visited[node] = true;
        todo[node] = true;
        
        for(auto it:g[node])
        {
            if(visited[it]==false)
            {
                if(iscyclic(g,todo,visited,it))
                    return true;
            }
            else if(todo[it])
                return true;
        }
        todo[node] = false;
        return false;
    }
};