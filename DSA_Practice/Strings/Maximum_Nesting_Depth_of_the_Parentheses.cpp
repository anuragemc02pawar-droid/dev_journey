class Solution {
public:
    int maxDepth(string s) {
        int n=s.length();
        int mx=0;
        int cnt=0;

        for(char c:s){
            if(c=='('){
                cnt++;
                mx=max(mx,cnt);
            }else if(c==')'){
                cnt--;
            }
        }
        return mx;
    }
};