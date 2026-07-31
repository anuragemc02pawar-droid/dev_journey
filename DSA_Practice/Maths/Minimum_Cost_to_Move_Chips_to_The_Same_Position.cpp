class Solution {
public:
    int minCostToMoveChips(vector<int>& position) {
        int n=position.size();
        int even=0;
        int odd=0;

        for(int x:position){
            if(x%2==0){
                even++;
            }else{
                odd++;
            }
        }
        return min(even,odd);

    }
};