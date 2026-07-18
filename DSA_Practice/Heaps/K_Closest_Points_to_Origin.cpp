class Solution {
public:
    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
        int n=points.size();
        priority_queue <pair<int,vector<int>>> maxh;

        for(int i=0;i<n;i++){
            maxh.push({(points[i][0]*points[i][0])+(points[i][1]*points[i][1]),points[i]});
            if(maxh.size()>k){
                maxh.pop();
            }
        }
        vector<vector<int>> res;
        while(!maxh.empty()){
            res.push_back(maxh.top().second);
            maxh.pop();
        }
        reverse(res.begin(),res.end());
        return res;
    }
};