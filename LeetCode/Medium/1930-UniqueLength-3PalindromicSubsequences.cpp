class Solution {
public:
    int countPalindromicSubsequence(string s) {
        vector<vector<int>> v(26, vector<int>(2, -1));
        for (int i=0;i<s.size();i++) {
            int idx = s[i]-'a';
            if (v[idx][0] == -1) {
                v[idx][0] = i;
            } else {
                v[idx][1] = i;
            } 
        }

        int ans = 0;
        for (int i=0;i<v.size();i++) {
            if (v[i][1] != -1) {
                unsigned int st = 0;
                for (int j=v[i][0]+1;j<v[i][1];j++) {
                    st |= (1<<(s[j]-'a'));
                }
                ans += std::popcount(st);
            }
        }
        return ans;
    }
};