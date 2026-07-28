class cmp{
    public:
    bool operator()(pair<int,string> &a,pair<int,string> &b){
        if(a.first==b.first){
            return a.second>b.second;
        }
        return b.first>a.first;
    }
};
class Solution {
public:
    vector<string> topKFrequent(vector<string>& words, int k) {
        int n=words.size();
        unordered_map<string,int> mp;
        priority_queue<pair<int,string>,vector<pair<int,string>>,cmp> pq;

        for(int i=0;i<n;i++){
            mp[words[i]]++;
        }
        for(auto it:mp){
            pq.push({it.second,it.first});
        }
        vector<string> ans;

        while(k--){
            ans.push_back(pq.top().second);
            pq.pop();
        }
        return ans;
    }
};