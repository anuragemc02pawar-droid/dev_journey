class Solution {
  public:
    void dfs(vector<int> adj[], vector<bool>& vis, int i,stack<int>& st){
        vis[i]=true;
        
        for(auto it:adj[i]){
            if(!vis[it]){
                dfs(adj,vis,it,st);
            }
        }
        st.push(i);
    }
    vector<int> topoSort(int V, vector<vector<int>>& edges) {
        vector<int> adj[V];
        for(auto &e:edges){
            int u=e[0];
            int v=e[1];
            
            adj[u].push_back(v);
        }
        vector<bool> vis(V,false);
        stack<int> st;
        
        for(int i=0;i<V;i++){
            if(!vis[i]){
                dfs(adj,vis,i,st);
            }
        }
        vector<int> res;
        while(!st.empty()){
            auto p=st.top();
            res.push_back(p);
            st.pop();
        }
        return res;
    }
};