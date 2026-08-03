class Solution {
public:
    string thousandSeparator(int n) {
        string s=to_string(n);
        int m=s.length();
        int cnt=0;
        for(int i=m-1;i>0;i--){
            cnt++;
            if(cnt==3){
                s.insert(i,".");
                cnt=0;
            }
        }
        return s;
    }
};