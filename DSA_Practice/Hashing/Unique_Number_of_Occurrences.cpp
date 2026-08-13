class Solution {
public:
    bool uniqueOccurrences(vector<int>& arr) {
        unordered_map<int,int> mp;
        int n=arr.size();

        for(auto c:arr){
            mp[c]++;
        }
        unordered_set<int> st;

        for(auto it:mp){
            if(st.count(it.second)){
                return false;
            }
            st.insert(it.second);
        }
        return true;
    }
};