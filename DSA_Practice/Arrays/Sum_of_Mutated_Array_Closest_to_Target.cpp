class Solution {
public:
    int findBestValue(vector<int>& arr, int target) {
      int n=arr.size();
      int low=0;
      int high = *max_element(arr.begin(), arr.end());
      while(low<high){
        int mid=low+(high-low)/2;
        int sum=0;
        for(int x:arr)
        sum+=min(x,mid);
        if(sum<target) low=mid+1;
        else high=mid;

        int sum1=0,sum2=0;
        for(int x:arr){
            sum1 += min(x,low);
            sum2 += min(x,low-1);
        }
        if(abs(sum2-target)<=abs(sum1-target)) return low-1;
        }
      
      
      return low;
    }
};