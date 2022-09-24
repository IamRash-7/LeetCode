class Solution {
public:
    bool exist(vector<vector<char>>& board, string word) {
        for(int i=0;i<board.size();i++)
        {
            for(int j=0;j<board[0].size();j++)
            {
                if(dfs(i,j,board,word,0))
                    return true;
            }
        }
        return false;
    }
    
    bool dfs(int row, int col, vector<vector<char>>& board, string word,int index)
    {
        if(index==word.size())
            return true;
        
        if(row<0 || row>=board.size() || col<0 || col>=board[0].size() || board[row][col]!=word[index])
            return false;
        
        char c = board[row][col];
        board[row][col] = '*';
        bool ret = dfs(row-1,col,board,word,index+1)||dfs(row+1,col,board,word,index+1)||dfs(row,col-1,board,word,index+1)||dfs(row,col+1,board,word,index+1);
        board[row][col] = c;
        return ret;
    }
};