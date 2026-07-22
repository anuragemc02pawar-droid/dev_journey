class Solution {
  public:
    vector<int> par;
    vector<int> rank;
    
    int find(int x){
            if(par[x]==x){
                return x;
            }
            return par[x]=find(par[x]);
        }
        
    void Union(int a, int b){
        int pa=find(a);
        int pb=find(b);
        
        if(pa==pb) return;
        
            par[pa]=pb;
        }
    vector<int> DSU(int n, vector<vector<int>>& queries) {
        vector<int> ans;
        par.resize(n+1);
        rank.resize(n+1,0);
        for(int i=1;i<n+1;i++){
            par[i]=i;
        }
        for(int i=0;i<queries.size();i++){
            if(queries[i][0]==2){
                int f=find(queries[i][1]);
                ans.push_back(f);
            }else if(queries[i][0]==1){
                Union(queries[i][1],queries[i][2]);
            }
        }
        return ans;
    }
};