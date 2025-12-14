class Solution {
public:
    int numberOfWays(string corridor) {
        int MOD = 1000000007;
        long long ans = 1;
        int sCnt = 0, cur = 1;
        bool flag = false;
        for (int i=0;i<corridor.size();i++) {
            if (sCnt == 2) {
                if (corridor[i] == 'S') {
                    ans *= cur;
                    ans %= MOD;
                    sCnt = 1;
                    cur = 1;
                } else {
                    cur++;
                }
            } else if (corridor[i] == 'S') {
                sCnt++;
                flag = true;
            }
        }
        if (!flag || sCnt == 1) return 0;
        return ans;
    }
};