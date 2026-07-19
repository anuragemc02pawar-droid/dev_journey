class Solution {
  public:
    vector<int> firstNegInt(vector<int>& arr, int k) {
        int min=0;
        int n=arr.size();
        int i=0;
        int j=0;
        deque<int> dq;
        vector<int> res;
        
        while(j<n){
            if(arr[j]<0){
                dq.push_back(arr[j]);
            }
            if(j-i+1<k){
                j++;
            }
            else if(j-i+1==k){
                if(dq.empty()){
                    res.push_back(0);
                }else{
                    res.push_back(dq.front());
                }
                if(!dq.empty() && arr[i]==dq.front()){
                    dq.pop_front();
                }
                i++;
                j++;
            }
        }
        return res;

    }
};