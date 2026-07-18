class Solution {
  public:
    int sumBetweenK1K2(vector<int>& arr, int k1, int k2) {
        int n=arr.size();
        priority_queue <int> maxh;
        
        for(int i=0;i<n;i++){
            maxh.push(arr[i]);
            if(maxh.size()>k2){
                maxh.pop();
            }
        }
        maxh.pop();
        int sum=0;
        while(maxh.size()>k1){
            sum+=maxh.top();
            maxh.pop();
        }
        return sum;
    }
};