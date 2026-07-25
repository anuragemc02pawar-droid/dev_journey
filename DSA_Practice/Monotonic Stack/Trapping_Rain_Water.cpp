class Solution {
public:
    int trap(vector<int>& height) {
        int n=height.size();
        vector<int> mxl;
        vector<int> mxr;
        int ans=0;
        int mx=0;

        for(int i=0;i<n;i++){
            mx=max(mx,height[i]);
            mxl.push_back(mx);
        }
        mx=0;
        for(int i=n-1;i>=0;i--){
            mx=max(mx,height[i]);
            mxr.push_back(mx);
        }
        reverse(mxr.begin(),mxr.end());

        for(int i=0;i<n;i++){
            ans+=(min(mxl[i],mxr[i])-height[i]);
        }
        return ans;
    }
};