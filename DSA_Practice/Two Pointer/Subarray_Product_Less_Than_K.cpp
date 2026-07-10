class Solution {
public:
    int numSubarrayProductLessThanK(vector<int>& nums, int k) {
        if(k<=1) return 0;

        int n=nums.size();
        int left=0;
        int ans=0;
        long long int prod=1;
        
        for(int right=0;right<n;right++){
            prod*=nums[right];

            while(prod>=k){
                prod/=nums[left];
                left++;
            }
            ans+=(right-left+1);
        }
        return ans;
    
    }
};