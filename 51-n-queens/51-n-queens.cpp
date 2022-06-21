class Solution {
public:
    vector<vector<string>> solveNQueens(int n) {
        vector<vector<string>>ans;
        vector<string> board(n);
        string s(n,'.');
        for(int i=0;i<n;i++)
        {
            board[i] = s;
        }
        recur(0,ans,board,n);
        return ans;
    }
    
    void recur(int col, vector<vector<string>>&ans,vector<string> &board, int n)
    {
        if(col==n)
        {
            ans.push_back(board);
            return;
        }
        for(int row=0;row<n;row++)
        {
            if(canfil(board,row,col,n))
            {
                board[row][col] = 'Q';
                recur(col+1,ans,board,n);
                board[row][col] = '.';
            }
        }
    }
    
    bool canfil(vector<string>&board, int row, int col,int n)
    {
        int duprow = row;
        int dupcol = col;
        
        while(row>=0 && col>=0)
        {
            if(board[row][col]=='Q')
                return false;
            row--;
            col--;
        }
        
        row = duprow;
        col = dupcol;
        
        while(col>=0)
        {
            if(board[row][col]=='Q')
                return false;
            col--;
        }
        
        row = duprow;
        col = dupcol;
        
        while(row<n && col>=0)
        {
            if(board[row][col]=='Q')
                return false;
            row++;
            col--;
        }
        return true;
    }
};