class Solution {
public:
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
        if(image[sr][sc]!=color)
            dfs(image,sr,sc,color,image[sr][sc]);
        return image;
    }
    
   void dfs(vector<vector<int>>& image, int sr, int sc, int color, int val)
    {
        if(sr >= image.size() || sc >= image[0].size() || sc<0 || sr<0)
            return;
        
        if(image[sr][sc]!=val)
            return;
        
        image[sr][sc] = color;
        vector<pair<int,int>> arr = {{-1,0},{0,-1},{1,0},{0,1}};
        for(auto i:arr)
        {
            dfs(image,sr+i.first,sc+i.second,color,val);
        }
    }
};