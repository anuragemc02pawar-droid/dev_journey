class Solution {
	public:
	vector<int> dijkstra(int V, vector<vector<int>> &edges, int src) {
		vector<vector<pair<int, int>> > adj(V);
		
		for (auto &e:edges) {
			int u = e[0];
			int v = e[1];
			int wt = e[2];
			adj[u].push_back({v, wt});
			adj[v].push_back({u, wt});
		}
		vector<int> dist(V, INT_MAX);
		dist[src] = 0;
		priority_queue <pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>> > pq;
		
		pq.push({0, src});
		
		while (!pq.empty()) {
		    auto d = pq.top().first;
			auto u = pq.top().second;
			pq.pop();
			if(d>dist[u]) continue;
			for (auto it : adj[u]) {
				int v = it.first;
				int wt = it.second;
				if(dist[v]>dist[u]+wt){
				    dist[v]=dist[u]+wt;
				    pq.push({dist[v],v});
				}
			}
		}
		return dist;
	}
};
