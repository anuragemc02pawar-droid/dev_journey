class Solution {
public:
    int totalFruit(vector<int>& fruits) {
        int n=fruits.size();
        int i=0;
        int j=0;
        int k=2;
        int mx=1;
        unordered_map <int,int> mp;

        while(j<n){
            mp[fruits[j]]++;
            if(mp.size()<=k){
                mx=max(mx,j-i+1);
                j++;
            }
            else if(mp.size()>k){
                while(mp.size()>k){
                    mp[fruits[i]]--;
                    if(mp[fruits[i]]==0){
                        mp.erase(fruits[i]);
                    }
                    i++;
                }
                j++;
            }
        }
        return mx;
    }
};