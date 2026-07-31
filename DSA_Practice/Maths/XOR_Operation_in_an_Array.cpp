class Solution {
public:
    int xorOperation(int n, int start) {
        vector<int> arr(n);
        int xr=0;
        for(int i=0;i<n;i++){
            arr[i]=start+2*i;
        }
        
        for(int i=0;i<n;i++){
            xr^=arr[i];
        }
        return xr;
    }
};