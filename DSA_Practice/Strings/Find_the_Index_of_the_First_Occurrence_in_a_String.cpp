class Solution {
public:
    int strStr(string haystack, string needle) {
        int n=haystack.size();
        int m=needle.size();

        if(haystack.find(needle)!=string::npos){
            return haystack.find(needle);
        }
        return -1;
    } 
};