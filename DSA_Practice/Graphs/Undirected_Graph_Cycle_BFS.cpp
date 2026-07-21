class Solution {
  public:
    bool bfs(vector<int> adj[],vector<bool>& vis,int src){
        queue <pair<int,int>> q;
        q.push({src,-1});
        vis[src]=true;
        
        while(!q.empty()){
            int node=q.front().first;
            int par=q.front().second;
            q.pop();
        for(auto it:adj[node]){
            if(!vis[it]){
                q.push({it,node});
                vis[it]=true;
            }
            else{
                if(it!=par) return true;
            }
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
                if(bfs(adj,vis,i)) return true;
            }
        }
        return false;
    }
};
