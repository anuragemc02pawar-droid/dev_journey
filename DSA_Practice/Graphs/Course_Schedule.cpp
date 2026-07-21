class Solution {
public:
    bool dfs(vector<int> adj[],vector<bool>& vis, vector<bool>& recPath, int i){
        vis[i]=true;
        recPath[i]=true;

        for(auto it:adj[i]){
            if(!vis[it]){
                if(dfs(adj,vis,recPath,it)){
                    return true;
                }
            }else{
                if(recPath[it]){
                    return true;
                }
            }
        }
        recPath[i]=false;
        return false;
    }
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        vector<int> adj[numCourses];

        for(auto &e:prerequisites){
            int u=e[0];
            int v=e[1];

            adj[u].push_back(v);
        }
        vector<bool> vis(numCourses,false);
        vector<bool> recPath(numCourses,false);

        for(int i=0;i<numCourses;i++){
            if(!vis[i]){
                if(dfs(adj,vis,recPath,i)){
                    return false;
                }
            }
        }
        return true;
    }
};