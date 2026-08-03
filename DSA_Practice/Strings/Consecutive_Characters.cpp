class Solution {
public:
    int maxPower(string s) {
        int n=s.length();

        int mx=1;
        int cnt=1;

        for(int i=1;i<n;i++){
            if(s[i]==s[i-1]){
                cnt++;
                mx=max(mx,cnt);
            }else{
                cnt=1;
            }
        }
        return mx;
    }
};