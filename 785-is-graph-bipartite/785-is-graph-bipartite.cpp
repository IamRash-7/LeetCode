class Solution {
public:
    bool isBipartite(vector<vector<int>>& graph) {
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
    }
    
};