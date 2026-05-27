class Solution {
public:
    int numberOfSpecialChars(string word) {
        vector<int> low(26, -1), high(26, -1);
        for (int i=0;i<word.size();i++) {
            if (word[i] <= 'Z') {
                if (high[word[i]-'A'] == -1) high[word[i]-'A'] = i;
            } else {
                low[word[i]-'a'] = i;
            }
        }
        int ans = 0;
        for (int i=0;i<26;i++) {
            if (low[i] != -1 && high[i] != -1 && low[i] < high[i]) ans++;
        }
        return ans;
    }
};