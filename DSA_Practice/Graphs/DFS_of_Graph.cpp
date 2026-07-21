class Solution {
  public:
    void DFS(vector<vector<int>>& adj, int src,vector<bool>& vis,vector<int>& lis){
        lis.push_back(src);
        vis[src]=true;
        
        for(auto it:adj[src]){
            if(!vis[it]){
                DFS(adj,it,vis,lis);
            }
        }
    }
    vector<int> dfs(vector<vector<int>>& adj) {
        int v=adj.size();
        vector<int> lis;
        vector<bool> vis(v,false);
        int src=0;
        DFS(adj,0,vis,lis);
        return lis;
    }
};