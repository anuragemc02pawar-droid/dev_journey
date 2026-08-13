class Solution {
public:
    vector<int> relativeSortArray(vector<int>& arr1, vector<int>& arr2) {
       unordered_map<int,int> mp;

       for(auto c:arr1){
        mp[c]++;
       }
       vector<int> ans;
       for(int i=0;i<arr2.size();i++){
        if(mp.count(arr2[i])){
            while(mp[arr2[i]]--){
                ans.push_back(arr2[i]);
            }
        }
       }
       unordered_set<int> st;

       for(auto c:arr2){
        st.insert(c);
       }
       sort(arr1.begin(),arr1.end());
       for(int i=0;i<arr1.size();i++){
        if(!st.count(arr1[i])){
            ans.push_back(arr1[i]);
        }
       }
       return ans;
    
       
    }
};