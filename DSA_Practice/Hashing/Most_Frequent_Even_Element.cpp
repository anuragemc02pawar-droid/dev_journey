class Solution {
public:
    int mostFrequentEven(vector<int>& nums) {
        sort(nums.begin(),nums.end());

        unordered_map<int,int> mp;
        for(auto c:nums){
            if(c%2==0)
            mp[c]++;
        }
        int ans=-1;
        int mx=0;
        for(auto c:nums){
            if(c%2==0 && mp[c]>mx){
                mx=mp[c];
                ans=c;
            }
        }
        return ans;
    }
};