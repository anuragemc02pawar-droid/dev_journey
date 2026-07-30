class Solution {
public:
    int missingNumber(vector<int>& nums) {
        int n=nums.size();
        unordered_map<int,int>mp;
        for(int i=0;i<=n;i++){
            mp[i]++;
        }
        for(int i=0;i<n;i++){
            if(mp[nums[i]]){
                mp.erase(nums[i]);
            }
        }
        return mp.begin()->first;
    }
};