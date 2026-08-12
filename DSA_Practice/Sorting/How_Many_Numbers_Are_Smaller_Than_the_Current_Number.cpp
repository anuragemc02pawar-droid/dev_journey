class Solution {
public:
    vector<int> smallerNumbersThanCurrent(vector<int>& nums) {
        int n=nums.size();
        vector<int> sorted=nums;
        vector<int> ans;

        sort(sorted.begin(),sorted.end());

        for(auto x:nums){
            ans.push_back(lower_bound(sorted.begin(),sorted.end(),x)-sorted.begin());
        }
        return ans;
        
    }
};