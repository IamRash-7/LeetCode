class Solution {
public:
    void gameOfLife(vector<vector<int>>& board) {
        vector<pair<int,int>> q;
        vector<int> r1 = {-1,0,1};
        int m = board.size();
        int n = board[0].size();
        
        for(int i=0;i<m;i++)
        {
            for(int j=0;j<n;j++)
            {
                int cnt=0;
                for(auto p : r1)
                {
                    for(auto q: r1)
                    {
                        int a = i-p;
                        int b = j-q;
                        if(a<0 || b<0 || a==m || b==n || (p==0 && q==0))
                            continue;
                        if(board[a][b]==1)
                            cnt++;
                    }
                }
                if(cnt <2 && board[i][j]==1)
                    q.push_back({i,j});
                if(cnt > 3 && board[i][j]==1)
                    q.push_back({i,j});
                if(cnt==3 && board[i][j]==0)
                    q.push_back({i,j});
            }
        }
        for(auto i : q)
        {
           board[i.first][i.second] = !board[i.first][i.second];
        }
        
    }
};