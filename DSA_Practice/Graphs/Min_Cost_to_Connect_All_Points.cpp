class Solution {
public:
    int minCostConnectPoints(vector<vector<int>>& points) {
        int n = points.size();
        vector<vector<int>> dist(n, vector<int>(n, 0));

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                dist[i][j] = abs(points[i][0] - points[j][0]) +
                             abs(points[i][1] - points[j][1]);
            }
        }
        priority_queue <pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>> pq;
        vector<bool> inMST(n, false);
        int mstCost = 0;

        pq.push({0,0});
        
        while(!pq.empty()){
            auto wt=pq.top().first;
            auto u=pq.top().second;
            pq.pop();
            if(inMST[u]) continue;
            inMST[u]=true;
            mstCost+=wt;
            
            for(int v=0;v<n;v++){
                if(!inMST[v]){
                    pq.push({dist[u][v],v});
                }
            }
        }
        return mstCost;
    }
};