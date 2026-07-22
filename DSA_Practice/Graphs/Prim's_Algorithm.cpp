class Solution {
  public:
    int spanningTree(int V, vector<vector<int>>& edges) {
        vector<bool> inMST(V,false);
        int cntMST=0;
        priority_queue <pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>> pq;
        pq.push({0,0});
        vector<vector<pair<int,int>>> adj(V);
        
        for(auto &e:edges){
            int u=e[0];
            int v=e[1];
            int wt=e[2];
            adj[u].push_back({v,wt});
            adj[v].push_back({u,wt});
        }
        
        while(!pq.empty()){
            auto u=pq.top().second;
            auto wt=pq.top().first;
            pq.pop();
            if(!inMST[u]){
                inMST[u]=true;
                cntMST+=wt;
                for(auto it:adj[u]){
                    int wt=it.second;
                    int v=it.first;
                    if(!inMST[v]){
                    pq.push({wt,v});
                    }
                }
            }
        }
        return cntMST;
    }
};