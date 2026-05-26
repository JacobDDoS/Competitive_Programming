class Solution {
public:
    int numberOfSpecialChars(string word) {
        vector<bool> low(26, false), upp(26, false);
        for (char a : word) {
            if (a >= 'a') low[a-'a'] = true;
            else upp[a-'A'] = true;
        }
        int ans = 0;
        for (int i=0;i<26;i++) {
            if (low[i] && upp[i]) ans++;
        }
        return ans;
    }
};