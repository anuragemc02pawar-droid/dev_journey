class Solution {
  public:
    vector<int> kLargest(vector<int>& arr, int k) {
        priority_queue <int,vector<int>,greater<int>> minh;
        
        int n=arr.size();
        for(int i=0;i<n;i++){
            minh.push(arr[i]);
            if(minh.size()>k){
                minh.pop();
            }
        }
        vector<int> res(k);
        
        for(int i=k-1;i>=0;i--){
            res[i]=minh.top();
            minh.pop();
        }
        return res;
    }
};