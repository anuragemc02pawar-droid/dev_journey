class Solution {
  public:
    void nearlySorted(vector<int>& arr, int k) {
        priority_queue <int,vector<int>,greater<int>> minh;
        
        int idx=0;
        int n=arr.size();
        for(int i=0;i<n;i++){
            minh.push(arr[i]);
            if(minh.size()>k){
                arr[idx++]=minh.top();
                minh.pop();
            }
        }
        while (!minh.empty()) {
            arr[idx++] = minh.top();
            minh.pop();
        }
    }
};