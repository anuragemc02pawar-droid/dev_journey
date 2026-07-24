class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        int n=heights.size();
        vector<int> nsl;
        vector<int> nsr;
        vector<int> ans(n,0);
        stack<int> st1;
        stack<int> st2;

        for(int i=0;i<n;i++){
            while(!st1.empty() && heights[st1.top()]>=heights[i]){
                st1.pop();
            }
            if(st1.empty()){
                nsl.push_back(-1);
            }else{
                nsl.push_back(st1.top());
            }
            st1.push(i);
        }
        for(int i=n-1;i>=0;i--){
            while(!st2.empty() && heights[st2.top()]>=heights[i]){
                st2.pop();
            }
            if(st2.empty()){
                nsr.push_back(n);  //if we didn't get any greater on right means it's out of right bound == n
            }else{
                nsr.push_back(st2.top());
            }
            st2.push(i);
        }
        reverse(nsr.begin(),nsr.end());
        for(int i=0;i<n;i++){
            ans[i]=(nsr[i]-nsl[i]-1)*heights[i];
        }
        
        return *max_element(ans.begin(),ans.end());
    }
};