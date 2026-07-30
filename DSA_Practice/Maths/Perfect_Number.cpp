class Solution {
public:
    bool checkPerfectNumber(int num) {
        if(num==1) return false;
        int cnt=1;
        int sum=0;
        while(cnt<=num/2){        
        if(num%cnt==0){
            sum+=cnt;
            cnt++;
        }
        else{
            cnt++;
        }
        
        }
        return sum==num;
    }
};