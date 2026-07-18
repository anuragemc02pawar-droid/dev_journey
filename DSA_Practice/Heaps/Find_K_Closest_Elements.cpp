class Solution {
public:
    vector<int> findClosestElements(vector<int>& arr, int k, int x) {
        int n=arr.size();
        priority_queue <pair<int,int>> maxh;

        for(int i=0;i<n;i++){
            maxh.push({abs(arr[i]-x),arr[i]});
            if(maxh.size()>k){
                maxh.pop();
            }
        }
        vector<int> res(k);
        for(int i=0;i<k;i++){
            res[i] =(maxh.top().second);
            maxh.pop();
        }
        sort(res.begin(),res.end());
        return res;
        
    }
};