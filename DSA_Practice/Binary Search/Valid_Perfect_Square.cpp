class Solution {
public:
    bool isPerfectSquare(int num) {
        int l=0;
        int r=num/2;
        if(num==0 || num==1) return true;

        while(l<=r){
            int mid=l+(r-l)/2;
            long long sq = 1LL * mid * mid;
            if(sq>num){
                r=mid-1;
            }
            if(sq<num){
                l=mid+1;
            }
            if(sq==num) return true;
        }
        return false;
    }
};