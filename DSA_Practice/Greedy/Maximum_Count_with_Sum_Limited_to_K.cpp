class Solution {
  public:
    int toyCount(vector<int> arr, int k) {
        sort(arr.begin(),arr.end());
        int n=arr.size();
        int i=0;
        int cnt=0;
        
        while(arr[i]<=k && i<n){
                k=k-arr[i];
                cnt++;
                i++;
    
        }
        return cnt;
    }
};