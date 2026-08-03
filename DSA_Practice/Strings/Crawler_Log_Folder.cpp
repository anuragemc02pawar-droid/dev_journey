class Solution {
public:
    int minOperations(vector<string>& logs) {
        int n=logs.size();
        string m="../";
        string r="./";
        string c="/";
        int cnt=0;

        for(int i=0;i<n;i++){
            if(logs[i].find(m)!=string::npos){
                if(cnt!=0){
                    cnt--;
                }
            }else if(logs[i].find(r)!=string::npos){
                cnt+=0;
            }else if(logs[i].find(c)!=string::npos){
                cnt++;
            }
        }
        return cnt;
    }
};