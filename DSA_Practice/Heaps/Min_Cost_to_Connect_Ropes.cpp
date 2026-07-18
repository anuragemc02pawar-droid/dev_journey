class Solution {
  public:
    int minCost(vector<int>& arr) {
        int n=arr.size();
        
        priority_queue <int,vector<int>,greater<int>> minh;
        
        for(int i=0;i<n;i++){
            minh.push(arr[i]);
        }
        int temp=minh.top();
        int sum=0;
        
        while(minh.size()>1){
            minh.pop();
            temp+=minh.top();
            sum+=temp;
            minh.pop();
            minh.push(temp);
            temp=minh.top();
        }
        return sum;
    }
};