class Solution {
	public:
	vector<int> par;
	vector<int> rank;
	
	int find(int x){
	    if(par[x]==x) return x;
	    return par[x]=find(par[x]);
	}
	void Union(int a,int b){
	    int pa=find(a);
	    int pb=find(b);
	    
	    if(pa==pb) return;
	    
	    if(rank[pa]==rank[pb]){
	        par[pb]=pa;
	        rank[pa]++;
	    }
	    else if(rank[pa]>rank[pb]){
	        par[pb]=pa;
	    }
	    else if(rank[pa]<rank[pb]){
	        par[pa]=pb;
	    }
	}
	
	static bool cmp(vector<int>& a, vector<int>& b) {
			return a[2] < b[2];
		}
		
	int kruskalsMST(int V, vector<vector<int>> &edges) {
		
		sort(edges.begin(),edges.end(),cmp);
		par.resize(V);
		rank.resize(V,0);
		for(int i=0;i<V;i++){
		    par[i]=i;
		}
		int mstCost=0;
		
		for(int i=0;i<edges.size();i++){
		    int u=edges[i][0];
		    int v=edges[i][1];
		    int wt=edges[i][2];
		    
		    if(find(u)!=find(v)){
		        mstCost+=wt;
		        Union(u,v);
		    }
		}
		return mstCost;
	}
};
