class Solution {
public:
    int secondHighest(string s) {
        unordered_set<int> st;

        for(auto c:s){
            if(isdigit(c)){
                st.insert(c-'0');
            }
        }
        int largest = -1, second = -1;
        for(auto x : st) {
            if(x > largest) {
                second = largest;
                largest = x;
            }
            else if(x > second) {
                second = x;
            }
        }
        return second;
    }
};