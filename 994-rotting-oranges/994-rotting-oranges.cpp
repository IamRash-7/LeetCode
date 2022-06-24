class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        queue<pair<int,int>> q;
        int row = grid.size();
        int col = grid[0].size();
        vector<int> dir={-1,0,1,0,-1};
        
        int fresh = 0;
        
        for(int i=0;i<row;i++)
        {
            for(int j=0;j<col;j++)
            {
                if(grid[i][j]==2)
                    q.push({i,j});
                if(grid[i][j]==1)
                    fresh++;
            }
        }
        int ans = -1;
        
        while(!q.empty())
        {
            int size = q.size();
            while(size--)
            {
                pair<int,int> p=q.front();
                q.pop();
                for(int i=0;i<4;i++)
                {
                    int r=p.first+dir[i];
                    int c=p.second+dir[i+1];
                    if(r>=0 && r<row && c>=0 && c<col &&grid[r][c]==1)
                    {
                        grid[r][c]=2;
                        q.push({r,c});
                        fresh--; 
                    }
                    
                }
            }
            ans++;
        }
        
        if(fresh>0)return -1;
        if(ans==-1)return 0;
        else return ans;
    }
};