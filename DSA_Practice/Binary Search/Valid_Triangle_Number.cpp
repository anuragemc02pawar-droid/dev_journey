class Solution {
public:
    int triangleNumber(vector<int>& nums) {
        int n=nums.size();
        sort(nums.begin(),nums.end());
        int cnt=0;
        for(int i=0;i<n-2;i++){
            if(nums[i]==0) continue;
            for(int j=i+1;j<n-1;j++){
                int sum=nums[i]+nums[j];
                int k=lower_bound(nums.begin()+j+1,nums.end(),sum)-nums.begin();

                cnt+=k-1-j;
            }
        }
       return cnt;
    }
};