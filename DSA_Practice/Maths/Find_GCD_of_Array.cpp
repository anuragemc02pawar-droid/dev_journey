class Solution {
public:
    int gcd(int a, int b) {
    while (b != 0) {
        int rem = a % b;
        a = b;
        b = rem;
    }
    return a;
}
    int findGCD(vector<int>& nums) {
        int n=nums.size();

        sort(nums.begin(),nums.end());
        int l=nums[0];
        int r=nums[n-1];
        
        return max(1,gcd(r,l));
    }
};