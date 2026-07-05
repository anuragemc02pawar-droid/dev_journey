class Solution {
public:
    string freqAlphabets(string s) {
        string res="";
        for(int i=s.length()-1;i>=0;){
            if(s[i]=='#'){
                int num=((s[i-2]-'0')*10 + (s[i-1]-'0'));
                res+=('a'+ num-1);
                i-=3;
            }else{
                res+=('a'+s[i]-'0'-1);
                i--;
            }
        }
        reverse(res.begin(),res.end());
        return res;
        
    }
};