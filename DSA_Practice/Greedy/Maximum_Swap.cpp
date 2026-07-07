class Solution {
public:
    int maximumSwap(int num) {
        string s=to_string(num);
        int n=s.size();
        for(int i=0;i<n;i++){
            int max=i;
            for(int j=i+1;j<n;j++){
                if(s[j]>=s[max]){
                    max=j;
                }
            }
            if(s[max]>s[i]){
                swap(s[i],s[max]);
                break;
            }
        }
        return stoi(s);
    }
};