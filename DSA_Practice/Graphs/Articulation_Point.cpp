class Solution {
  public:
    void dfs(vector<int> adj[],vector<bool>& vis,vector<int>& dt,vector<int>& lt,vector<bool>& isAP,int& t,vector<int>& ans,int par,int i){
        vis[i]=true;
        t++;
        dt[i]=t;
        lt[i]=t;
        int children=0;
        
        for(auto it:adj[i]){
            if(!vis[it]){
                children++;
                dfs(adj,vis,dt,lt,isAP,t,ans,i,it);
                lt[i]=min(lt[i],lt[it]);
                if(par != -1 && lt[it] >= dt[i]){
                  isAP[i] = true;
            }
                
            }
            else{
                if(it!=par){
                    lt[i]=min(lt[i],dt[it]);
                }
            }
            
        }
        if(children>1 && par==-1){
            isAP[i]=true;
        }
    }
    vector<int> articulationPoints(int V, vector<vector<int>>& edges) {
        vector<int> dt(V,0);
        vector<int> lt(V,0);
        int t=0;
        vector<bool> vis(V,false);
        vector<bool> isAP(V,false);
        vector<int> adj[V];
        for(auto &e:edges){
            int u=e[0];
            int v=e[1];
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        int par=-1;
        vector<int> ans;
        
        for(int i=0;i<V;i++){
            if(!vis[i]){
                dfs(adj,vis,dt,lt,isAP,t,ans,par,i);
            }
        }
        for(int i=0;i<V;i++){
            if(isAP[i]){
                ans.push_back(i);
            }
        }
        if(ans.size()!=0) return ans;
        return {-1};
    }
};