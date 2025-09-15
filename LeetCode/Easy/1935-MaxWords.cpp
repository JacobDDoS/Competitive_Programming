class Solution {
public:
    int canBeTypedWords(string text, string brokenLetters) {
        vector<bool> broke(26, false);
        for (char c : brokenLetters) {
            broke[c-'a'] = true;
        }
        int ans = 0;
        bool flag = true;
        for (int i=0;i<text.size();i++) {
            if (text[i] == ' ') {
                if (flag) {
                    ans++; 
                } else {
                    flag = true;
                }
            } else if (broke[text[i]-'a']) {
                flag = false;
            }
        }
        ans += (flag ? 1 : 0);
        return ans;
    }
};