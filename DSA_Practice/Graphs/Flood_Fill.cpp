class Solution {
public:
    
    void dfs(vector<vector<int>>& image,vector<vector<int>>& copy,vector<vector<bool>>& vis,int sr,int sc,int color){
        int m=image.size();
        int n=image[0].size();

        vis[sr][sc]=true;
        copy[sr][sc]=color;

        if(sr+1<m && image[sr+1][sc]==image[sr][sc] && !vis[sr+1][sc]){
            dfs(image,copy,vis,sr+1,sc,color);
        }
        if(sr-1>=0 && image[sr-1][sc]==image[sr][sc] && !vis[sr-1][sc]){
            dfs(image,copy,vis,sr-1,sc,color);
        }
        if(sc+1<n && image[sr][sc+1]==image[sr][sc] && !vis[sr][sc+1]){
            dfs(image,copy,vis,sr,sc+1,color);
        }
        if(sc-1>=0 && image[sr][sc-1]==image[sr][sc] && !vis[sr][sc-1]){
            dfs(image,copy,vis,sr,sc-1,color);
        }

    }
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
        int m=image.size();
        int n=image[0].size();
        vector<vector<bool>> vis(m,vector<bool>(n,false));
        vector<vector<int>> copy=image;
        
        
        dfs(image,copy,vis,sr,sc,color);
        return copy;
    }
};