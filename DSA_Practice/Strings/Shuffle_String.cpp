class Solution {
public:
    string restoreString(string s, vector<int>& indices) {
        int n=s.length();
        string a=s;

        for(int i=0;i<n;i++){
            a[indices[i]]=s[i];
        }
        return a;
    }
};