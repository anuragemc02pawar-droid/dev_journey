class Solution {
  public:
    vector<int> bellmanFord(int V, vector<vector<int>>& edges, int src) {
        vector<int> dist(V,100000000);
        dist[src]=0;
        
        
        for(int i=0;i<V-1;i++){
            for(auto &e:edges){
            int u=e[0];
            int v=e[1];
            int wt=e[2];
            
            if(dist[u] !=100000000 && dist[v]>dist[u]+wt){
                dist[v]=dist[u]+wt;
            }
        }
        }
        
        for(auto &e : edges) {
            int u = e[0];
            int v = e[1];
            int wt = e[2];

            if(dist[u] != 100000000 && dist[v] > dist[u] + wt) {
                return {-1};
            }
        }
        return dist;
    }
};
