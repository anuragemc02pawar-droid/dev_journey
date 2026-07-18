class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        int n=nums.size();
        unordered_map <int,int> mp;
        for(int i=0;i<n;i++){
            mp[nums[i]]++;
        }
        priority_queue <pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>> minh;

        for(auto i=mp.begin();i!=mp.end();i++){
            minh.push({i->second,i->first});
            if(minh.size()>k){
                minh.pop();
            }
        }
        vector<int> res(k);
        for(int i=0;i<k;i++){
            res[i]=minh.top().second;
            minh.pop();
        }
        return res;
    }
};