class Solution {
public:
    bool dfs(vector<int> adj[], vector<bool>& vis, vector<bool>& recPath,
             stack<int>& st, int i) {
        vis[i] = true;
        recPath[i] = true;

        for (auto it : adj[i]) {
            if (!vis[it]) {
                if (dfs(adj, vis, recPath, st, it)) {
                    return true;
                }
            } else {
                if (recPath[it]) {
                    return true;
                }
            }
        }
        st.push(i);
        recPath[i] = false;
        return false;
    }
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        vector<int> adj[numCourses];
        for (auto& e : prerequisites) {
            int u = e[0];
            int v = e[1];
            adj[v].push_back(u);
        }
        vector<bool> vis(numCourses, false);
        stack<int> st;
        vector<bool> recPath(numCourses, false);
        vector<int> ans;

        for (int i = 0; i < numCourses; i++) {
            if (!vis[i]) {
                if (dfs(adj, vis, recPath, st, i)) {
                    return ans;
                }
            }
        }
        while (!st.empty()) {
            auto p = st.top();
            ans.push_back(p);
            st.pop();
        }
        return ans;
    }
};