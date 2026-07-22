class Solution {
public:
    void dfs(vector<vector<int>>& isConnected,vector<bool>& vis, int u){
        vis[u]=true;
        int n=isConnected.size();
        for(int v=0;v<n;v++){
            if(isConnected[u][v]==1 && !vis[v]){
                dfs(isConnected,vis,v);
            }
        }
    }
    int findCircleNum(vector<vector<int>>& isConnected) {
        int n=isConnected.size();
        int m=isConnected[0].size();

        vector<bool> vis(n,false);
        int cnt=0;

        for(int i=0;i<n;i++){
                if(!vis[i]){
                    dfs(isConnected,vis,i);
                    cnt++;
                }
        }
        return cnt;
    }
};