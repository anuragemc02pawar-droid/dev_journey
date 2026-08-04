class Solution {
public:
    bool canConstruct(string ransomNote, string magazine) {
        int n=magazine.size();
        int m=ransomNote.size();

        unordered_map<char,int> mp;

        for(auto c:magazine){
            mp[c]++;
        }
        for(char c:ransomNote){
            if(mp.count(c)==0 || mp[c]==0){
                return false;
            }
            mp[c]--;
        }
        return true;
    }
};