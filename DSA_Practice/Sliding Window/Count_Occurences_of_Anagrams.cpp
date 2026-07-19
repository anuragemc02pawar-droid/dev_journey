class Solution {
public:
    int search(string &pat, string &txt) {

        int n = txt.length();
        int k = pat.length();

        unordered_map<char, int> mp;

        for (char c : pat) {
            mp[c]++;
        }

        int cnt = mp.size();
        int ans = 0;

        int i = 0, j = 0;

        while (j < n) {

            // Add current character to window
            if (mp.count(txt[j])) {
                mp[txt[j]]--;

                if (mp[txt[j]] == 0)
                    cnt--;
            }

            if (j - i + 1 < k) {
                j++;
            }
            else if(j-i+1==k){

                if (cnt == 0)
                    ans++;

                // Remove leftmost character from window
                if (mp.count(txt[i])) {

                    if (mp[txt[i]] == 0)
                        cnt++;

                    mp[txt[i]]++;
                }

                i++;
                j++;
            }
        }

        return ans;
    }
};