class Solution {
public:
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {
        vector<vector<pair<int,int>>> adj(n);
        for(auto &f:flights){
            int u=f[0];
            int v=f[1];
            int cst=f[2];
            adj[u].push_back({v,cst});
        }

        vector<int> dist(n,INT_MAX);
        dist[src]=0;
        
        queue <tuple<int,int,int>> q;
        
        q.push({src,0,-1});
        while(!q.empty()){
            auto[u,cst,st]=q.front();

            q.pop();
            for(auto v:adj[u]){
                if(dist[v.first]>cst+v.second && st+1<=k){
                    dist[v.first]=cst+v.second;
                    q.push({v.first,dist[v.first],st+1});
                }
            }
        }
        if(dist[dst]!=INT_MAX) return dist[dst];
        return -1;
    }
};