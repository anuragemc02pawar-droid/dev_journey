class Solution {
  public:
    bool dfs(vector<int> adj[], vector<bool>& vis, vector<bool> &recPath,int i){
        vis[i]=true;
        recPath[i]=true;
        
        for(auto it:adj[i]){
            if(!vis[it]){
                if(dfs(adj,vis,recPath,it)){
                    return true;
                }
            }else{
                if(recPath[it]){
                    return true;
                }
            }
        }
        recPath[i]=false;
        return false;
    }
    bool isCyclic(int V, vector<vector<int>> &edges) {
        vector<int> adj[V];
        for(auto &e:edges){
            int u=e[0];
            int v=e[1];
            
            adj[u].push_back(v);
        }
        vector<bool> vis(V,false);
        vector<bool> recPath(V,false);
        
        for(int i=0;i<V;i++){
            if(!vis[i]){
                if(dfs(adj,vis,recPath,i)){
                return true;
                }
            }
        }
        return false;

    }
};