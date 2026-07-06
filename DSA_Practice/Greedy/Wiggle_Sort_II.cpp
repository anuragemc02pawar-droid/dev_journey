class Solution {
public:
    void wiggleSort(vector<int>& nums) {
        int n=nums.size();
        sort(nums.begin(),nums.end());
        vector<int> reo(n);
        int j=n-1;
        int i=1;
        while(i<n){
            reo[i]=nums[j];
            i+=2;
            j--;
        }
        i=0;
        while(i<n){
            reo[i]=nums[j];
            i+=2;
            j--;
        }
        for(int i=0;i<n;i++){
            nums[i]=reo[i];
        }
    }
};