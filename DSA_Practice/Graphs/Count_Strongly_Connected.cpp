class Solution {
  public:
    void kosaraju(vector<int> trans[],vector<bool>& visi,int t){
        visi[t]=true;
        
        for(auto it:trans[t]){
            if(!visi[it]){
                kosaraju(trans,visi,it);
            }
        }
    }
    void dfs(vector<int> adj[],vector<bool>& vis,stack<int>& st,int i){
        vis[i]=true;
        
        for(auto it:adj[i]){
            if(!vis[it]){
                dfs(adj,vis,st,it);
            }
        }
        st.push(i);
    }
    int kosaraju(int V, vector<vector<int>> &edges) {
        vector<int> adj[V];
        vector<bool> vis(V,false);
        stack<int> st;
        vector<int> trans[V];
        
        for(auto &e:edges){
            int u=e[0];
            int v=e[1];
            adj[u].push_back(v);
            trans[v].push_back(u);
        }
        
        for(int i=0;i<V;i++){
            if(!vis[i]){
                dfs(adj,vis,st,i);
            }
        }
        int cnt=0;
        vector<bool> visi(V,false);
        while(!st.empty()){
            auto t=st.top();
            st.pop();
            if(!visi[t]){
            kosaraju(trans,visi,t);
            cnt++;
            }
            
        }
        return cnt;
    }
};