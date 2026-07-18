class Solution {
  public:
    int kthSmallest(vector<int> &arr, int k) {
        priority_queue <int> maxh;
        
        int n=arr.size();
        
        for(int i=0;i<n;i++){
            maxh.push(arr[i]);
            if(maxh.size()>k){
                maxh.pop();
            }
        }
        return maxh.top();
    }
};