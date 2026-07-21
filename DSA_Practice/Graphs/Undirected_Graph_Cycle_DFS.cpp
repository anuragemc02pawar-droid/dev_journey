class Solution {
  public:
    bool dfs(vector<int> adj[],vector<bool>& vis, int par, int src){
        vis[src]=true;
        
        for(auto it:adj[src]){
            if(!vis[it]){
                if(dfs(adj,vis,src,it)) return true;
            }
            else{
                if(it!=par) return true;
            }
        }
        return false;
    }
    bool isCycle(int V, vector<vector<int>>& edges) {
        vector<int> adj[V];
        
        for(auto &e:edges){
            int u=e[0];
            int v=e[1];
            
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        vector<bool> vis(V,false);
        
        for(int i=0;i<V;i++){
            if(!vis[i]){
                if(dfs(adj,vis,-1,i)) return true;
            }
        }
        return false;
    }
};