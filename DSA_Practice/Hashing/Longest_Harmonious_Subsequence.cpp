class Solution {
public:
    int findLHS(vector<int>& nums) {
        int n=nums.size();
        unordered_map<int,int> mp;

        for(auto &w:nums){
            mp[w]++;
        }
        int ans=0;
        for(auto it:mp){
            if(mp.count(it.first+1)){
                ans=max(ans,it.second + mp[it.first+1]);
            }
        }
        return ans;        
    }
};