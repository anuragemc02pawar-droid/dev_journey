class Solution {
public:
    vector<string> findRelativeRanks(vector<int>& score) {
        int n=score.size();
        vector<string> ans(n);
        unordered_map<int,int> mp;
        for(int i=0;i<n;i++){
            mp[score[i]]=i;
        }
        sort(score.begin(),score.end());
        reverse(score.begin(),score.end());

        for(int i=0;i<n;i++){
            int idx=mp[score[i]];
            if(i==0){
                ans[idx]="Gold Medal";
            }
            else if(i==1){
                ans[idx]="Silver Medal";
            }
            else if(i==2){
                ans[idx]="Bronze Medal";
            }
            else{
                ans[idx]=to_string(i+1);
            }
        }
        return ans;
              
    }
};