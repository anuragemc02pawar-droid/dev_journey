class Solution {
public:
    int findPeakElement(vector<int>& nums) {
        int n=nums.size();
        int idx=0;

        for(int i=0;i<n;i++){
            if(nums[i]>nums[idx]){
                idx=i;
            }
        }
        return idx;
    }
};