class Solution {
public:
    int maxOperations(string s) {
        int ans = 0, cur = 0;
        for (int i=0;i<s.size();i++) {
            if (s[i] == '1') {
                while (i<s.size() && s[i] == '1') {
                    cur++;
                    i++;
                }
                i--;
            } else {
                ans += cur;
                while (i<s.size() && s[i] == '0') {
                    i++;
                }
                i--;
            }
        }
        return ans;
    }
};