class Solution {
public:
    bool isIsomorphic(string s, string t) {
        int n=s.length();
        unordered_map<char,int> sp;
        unordered_map<char,int> tp;

        for(int i=0;i<n;i++){
            if(sp.count(s[i])){
                if(sp[s[i]]!=t[i]){
                    return false;
                }
            }else{
                sp[s[i]]=t[i];
            }
            if(tp.count(t[i])){
                if(tp[t[i]]!=s[i]){
                    return false;
                }
            }else{
                tp[t[i]]=s[i];
            }
        }

        return true;
    }
};