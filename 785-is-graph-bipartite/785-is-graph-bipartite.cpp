class Solution {
public:
    bool isBipartite(vector<vector<int>>& graph) {
        // BFS
        /*
        vector<int> color(graph.size(),0);
        queue<int>q;
        
        for(int i=0;i<graph.size();i++)
        {
            if(color[i]) continue;
            
            q.push(i);
            color[i]=1;
            
            while(!q.empty())
            {
                int top = q.front();
                
                for(auto ele:graph[top])
                {
                    if(!color[ele])
                    {
                        color[ele] = -color[top];
                        q.push(ele);
                    }
                    else if(color[ele] == color[top])
                        return false;
                }
                q.pop();
            }
        }
        return true;
        */
        
        //DFS
        vector<int> color(graph.size(),0);
        for(int i=0;i<graph.size();i++)
        {
            if(color[i])
                continue;
            
            color[i] = 1;
            if(dfs(i,color,graph)==false)
                return false;
        }
        return true;
    }
    
    bool dfs(int node, vector<int>& color, vector<vector<int>>& graph)
    {
        for(auto itr : graph[node])
        {
            if(color[itr]==0)
            {
                color[itr] = -color[node];
                if(dfs(itr,color,graph)==false)
                    return false;
            }
            else if(color[itr]==color[node])
                return false;
        }
        return true;
    }
    
};