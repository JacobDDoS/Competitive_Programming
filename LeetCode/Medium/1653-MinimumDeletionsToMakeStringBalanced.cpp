class Solution {
public:
    int minimumDeletions(string s) {
        int aCnt=0,bCnt=0;
        for (char c:s) {
            if (c=='a') aCnt++;
        }

        int ans = min(aCnt, (int)s.size()-aCnt);
        for (int i=0;i<s.size();i++) {
            ans = min(ans, aCnt+bCnt);
            if (s[i]=='b') bCnt++;
            else aCnt--;
        }
        return ans;
    }
};