class Solution {
public:
    vector<int> selfDividingNumbers(int left, int right) {
        vector<int> ans;

        for(int i=left;i<=right;i++){
            if(i<10){
                ans.push_back(i);
            }
            else{
                int n=i;
                while(n>0){
                    int d=n%10;
                    if(d==0 || i%d!=0){
                        break;
                    }
                    n/=10;
                }
                if(n==0) ans.push_back(i);
            }
        }
        return ans;
    }
};