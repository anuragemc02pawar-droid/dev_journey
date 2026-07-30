class Solution {
public:
    int findNumbers(vector<int>& nums) {
        int n=nums.size();
        vector<string> s(n);

        int cnt=0;
        for(int i=0;i<n;i++){
            s[i]=to_string(nums[i]);
            if((s[i].length())%2==0) cnt++;
        }
        return cnt;
    }
};