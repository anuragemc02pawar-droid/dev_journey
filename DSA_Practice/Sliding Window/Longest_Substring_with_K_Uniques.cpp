class Solution {
  public:
    int longestKSubstr(string &s, int k) {
        int n=s.length();
        int i=0;
        int j=0;
        unordered_map <char,int> mp;
        int sz=-1;
        while(j<n){
            mp[s[j]]++;
            
            if(mp.size()<k){
                j++;
            }
            else if(mp.size()==k){
                sz=max(sz,j-i+1);
                j++;
                
            }
            else if(mp.size()>k){
                while(mp.size()>k){
                    mp[s[i]]--;
                    if(mp[s[i]]==0){
                        mp.erase(s[i]);
                    }
                    i++;
                }
            
                j++;
            }
        }
        return sz;

    }
};