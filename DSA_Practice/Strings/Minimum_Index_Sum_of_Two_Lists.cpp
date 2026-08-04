class Solution {
public:
    vector<string> findRestaurant(vector<string>& list1, vector<string>& list2) {
        int n=list1.size();
        int m=list2.size();
        int mn=INT_MAX;
        unordered_map<string,int> mp;
        vector<string> ans;

        for(int i=0;i<n;i++){
            mp[list1[i]]=i;
        }
        for(int i=0;i<m;i++){
            int sum=0;
            if(mp.count(list2[i])){
                sum=i+mp[list2[i]];
                

                if(sum<mn){
                    mn=min(sum,mn);
                    ans.clear();
                    ans.push_back(list2[i]);
                }else if(sum==mn){
                    ans.push_back(list2[i]);
                }

            }
        }
        return ans;
        

    }
};