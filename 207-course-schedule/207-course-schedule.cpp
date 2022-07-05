class Solution {
public:
    bool canFinish(int n, vector<vector<int>>& prerequisites) {
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
    }
};