class Solution {
public:
    void solveSudoku(vector<vector<char>>& board) {
        recur(board);
    }
    
    bool recur(vector<vector<char>>& board)
    {
        vector<char> vals = {'1','2','3','4','5','6','7','8','9'};
        for(int i =0;i<board.size();i++)
        {
            for(int j=0;j<board[0].size();j++)
            {
                if(board[i][j]=='.')
                {
                    for(char val:vals)
                    {
                        if(isvalid(i,j,val,board))
                        {
                            board[i][j] = val;

                            if(recur(board)==true)
                                return true;
                            else
                                board[i][j] = '.';
                        }
                    }
                    return false;
                }
            }
        }
        return true;
    }
    
    bool isvalid(int row, int col, char c, vector<vector<char>>& board)
    {
        for(int i=0;i<board.size();i++)
        {
            if(board[i][col]==c)
                return false;
            if(board[row][i]==c)
                return false;
            if(board[3*(row/3) + i/3][3*(col/3) + i%3]==c)
                return false;
        }
        return true;
    }
};