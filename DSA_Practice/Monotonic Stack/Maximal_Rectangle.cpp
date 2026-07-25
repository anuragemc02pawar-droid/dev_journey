class Solution {
public:
    int MAH(vector<int> rect){
        vector<int> nsr;
        vector<int> nsl;
        vector<int> ans(rect.size(),0);
        stack<int> st1;
        stack<int> st2;

        for(int i=0;i<rect.size();i++){
            while(!st1.empty() && rect[st1.top()]>=rect[i]){
                st1.pop();
            }
            if(st1.empty()){
                nsl.push_back(-1);
            }else{
                nsl.push_back(st1.top());
            }
            st1.push(i);
        }
        for(int i=rect.size()-1;i>=0;i--){
            while(!st2.empty() && rect[st2.top()]>=rect[i]){
                st2.pop();
            }
            if(st2.empty()){
                nsr.push_back(rect.size());
            }else{
                nsr.push_back(st2.top());
            }
            st2.push(i);
        }
        reverse(nsr.begin(),nsr.end());

        for(int i=0;i<rect.size();i++){
            ans[i]=rect[i]*(nsr[i]-nsl[i]-1);
        }
        return *max_element(ans.begin(),ans.end());
    }
    int maximalRectangle(vector<vector<char>>& matrix) {
        
        if(matrix.empty()) return 0;

        vector<int> v;
        int n=matrix.size();
        int m=matrix[0].size();
        int mx=0;
        vector<vector<int>> mat(n, vector<int>(m));

        for(int i = 0; i < n; i++) {
           for(int j = 0; j < m; j++) {
            mat[i][j] = matrix[i][j] - '0';
            }
        }
        for(int i=0;i<1;i++){
            for(int j=0;j<m;j++){
                v.push_back(mat[i][j]);
            }
            int a=MAH(v);
            mx=max(mx,a);
        }
        for(int i=1;i<n;i++){
            for(int j=0;j<m;j++){
                if(mat[i][j]==0){
                    v[j]=0;
                }else{
                    v[j]=mat[i][j]+v[j];
                }
            }
            int a=MAH(v);
            mx=max(mx,a);
        }
        return mx;
    }
};