class Solution {
  public:
    vector<int> prevSmaller(vector<int>& arr) {
        vector<int> ans;
        int n=arr.size();
        set<int> s;
        
        for(auto x:arr){
            auto it=s.lower_bound(x);
            
            if(it==s.begin()){
                ans.push_back(-1);
            }
            else{
                --it;
                ans.push_back(*it);
            }
            s.insert(x);
        }
return ans;
    }
};