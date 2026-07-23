class Solution {
  public:
    bool dfs(vector<int> adj[],vector<bool>& vis,vector<int>& dt,vector<int>& lt,int par,int& t, int i,int& c,int&d){
        vis[i]=true;
        t++;
        dt[i]=t;
        lt[i]=t;
        
        for(auto it:adj[i]){
            if(!vis[it]){
                if(dfs(adj,vis,dt,lt,i,t,it,c,d)) return true;
                lt[i]=min(lt[i],lt[it]);
                if(lt[it]>dt[i]){
                    if((i==c && it==d) || (i==d && it==c)){
                    return true;
                }
                }
                
            }else{
                if(it!=par){
                    lt[i]=min(lt[i],dt[it]);
                }
            }
        }
        return false;
    }
    bool isBridge(int V, vector<vector<int>> &edges, int c, int d) {
        vector<int> dt(V,0);
        vector<int> lt(V,0);
        int t=0;
        vector<bool> vis(V,false);
        vector<int> adj[V];
        int par=-1;
        
        for(auto &e:edges){
            int u=e[0];
            int v=e[1];
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        
        for(int i=0;i<V;i++){
            if(!vis[i]){
                if(dfs(adj,vis,dt,lt,par,t,i,c,d)) return true;
            }
        }
        return false;

    }
};