class Solution {
  public:
    vector<int> calculateSpan(vector<int>& arr) {
        int n=arr.size();
        stack<int> st;
        vector<int> ans(n,0);
        
        for(int i=0;i<n;i++){
            while(!st.empty() && arr[st.top()]<=arr[i]){
                st.pop();
            }
            if(st.empty()){ //stack is empty means we travelled out left and didn't find ngl for i so all were lesser than it, so i-(-1) =i+1 
            ans[i]=i+1;
                
            }else{
                ans[i]=i-st.top();
            }
            st.push(i);
        }
        
        return ans;
    }
};