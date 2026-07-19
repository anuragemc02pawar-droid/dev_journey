class Solution {
  public:
    int maxSubarraySum(vector<int>& arr, int k) {
        int n=arr.size();
        int start=0;
        int end=0;
        int sum=0;
        int mx=INT_MIN;

        while(end<n){
             sum+=arr[end];
            if(end-start+1 < k){
                end++;
               
            }
            else if(end-start+1==k){
                mx=max(mx,sum);
                sum-=arr[start];
                end++;
                start++;
            }
        }
        return mx;

    }
};