class Solution {
public:
    int integerReplacement(long long int n) {
        int cnt=0;
        if(n==1) return 0;
        while(n!=1){
        if(n%2==0){
            n=n/2;
            cnt++;
        }
        else if(n==3 || n%4==1){
            n--;
            cnt++;
        }else{
            n++;
            cnt++;
        }
        
        }
        return cnt;

    }
};