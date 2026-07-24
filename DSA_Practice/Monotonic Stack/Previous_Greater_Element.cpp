class Solution {
  public:
    vector<int> preGreaterEle(vector<int>& arr) {
        vector<int> ans;
        int n=arr.size();
        stack<int> st;

        for(int i=0;i<n;i++){
            while(!st.empty() && st.top()<=arr[i]){
                st.pop();
            }
            if(st.empty()){
                ans.push_back(-1);
            }else{
                ans.push_back(st.top());
            }
            st.push(arr[i]);
        }
        return ans;
    }
};