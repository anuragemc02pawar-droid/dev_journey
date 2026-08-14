class Solution {
public:
    string kthDistinct(vector<string>& arr, int k) {
        unordered_map<string,int> mp;

        for(string s:arr){
            mp[s]++;
        }
        int cnt=0;

        for(int i=0;i<arr.size();i++){
            if(mp[arr[i]]==1){
                cnt++;
            }
            if(cnt==k){
                return arr[i];
            }
        }
        return "";
    }
};