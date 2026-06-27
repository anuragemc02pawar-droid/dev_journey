class Solution {
  public:
    int minSteps(vector<int>& arr, int start, int end) {
        
        if(start == end) return 0;
        
        queue<int> q;
        q.push(start);
        
        vector<int> dist(100000, INT_MAX);
        dist[start] = 0;
        
        while(!q.empty()){
            int node = q.front();
            q.pop();
            
            for(auto it : arr){
                int num = (1LL * it * node) % 1000;
                
                if(dist[node] + 1 < dist[num]){
                    dist[num] = dist[node] + 1;
                    
                    if(num == end) return dist[num];
                    
                    q.push(num);
                }
            }
        }
        
        return -1;
    }
};