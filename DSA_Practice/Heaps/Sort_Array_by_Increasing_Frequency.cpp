class Solution {
public:
    vector<int> frequencySort(vector<int>& nums) {
        int n=nums.size();
        unordered_map <int,int> mp;

        for(int i=0;i<n;i++){
            mp[nums[i]]++;
        }
        priority_queue <pair<int,int>> maxh;

        for(auto i=mp.begin();i!=mp.end();i++){
            maxh.push({i->second,-i->first});
        }
        vector<int> res(n);
        int idx=n-1;
        while(!maxh.empty()){
            int freq=maxh.top().first;
            int num=-maxh.top().second;
            while(freq--){
                res[idx--]=num;
            }
            maxh.pop();
        }
        return res;
    }
};