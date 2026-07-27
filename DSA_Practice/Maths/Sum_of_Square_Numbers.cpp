class Solution {
public:
    bool judgeSquareSum(int c) {
        int a=0;
        int b=sqrt(c);


        while(a<=b){
            long long sum = 1LL * a * a + 1LL * b * b;
            if(sum==c){
                return true;
            }
            if(sum>c){
                b--;
            }
            if(sum<c){
                a++;
            }
        }
        return false;
    }
};