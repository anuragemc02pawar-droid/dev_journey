class Solution {
public:
    
    bool canbePlaced(vector<int>& position, int dist, int m){
        int cntball=1; int last=position[0]; int n = position.size();
        for(int i=1;i<n;i++){
        if(position[i]-last>=dist){
            cntball++;
            last=position[i];
        }
        }
        if(cntball>=m) return true;
        return false;
    }
    
    int maxDistance(vector<int>& position, int m) {
        sort(position.begin(),position.end());
        int n=position.size();
        int low=0;int high=position[n-1]-position[0];
        while(low<=high){
            int mid = low + (high-low)/2;
        if(canbePlaced(position,mid,m)==true){
            low=mid+1;
        }else{
            high=mid-1;
        }
        }
        return high;
    }
};