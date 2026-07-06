class Solution {
public:
    int wiggleMaxLength(vector<int>& nums) {
        int n=nums.size();
        int prevDiff=0;
        int cnt=1;
        int i=1;
        while(i<n){
            int currDiff=nums[i]-nums[i-1];
            if(prevDiff<=0 && currDiff>0){
                cnt++;
                prevDiff=currDiff;
            }else if(prevDiff>=0 && currDiff<0){
                cnt++;
                prevDiff=currDiff;
            }
            i++;
    }
    return cnt;
    }
};