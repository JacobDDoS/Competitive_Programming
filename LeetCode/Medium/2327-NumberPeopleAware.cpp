class Solution {
public:
    int peopleAwareOfSecret(int n, int delay, int forget) {
        vector<int> start(2001), end(2001);
        start[delay] = 1;
        end[forget] = 1;
        int MOD = 1000000007;
        int curActive = 0, total = 1;

        for (int i=1;i<n;i++) {
            curActive += start[i] - end[i];
            curActive %= MOD;
            if (curActive < 0) {
                curActive += MOD;
            }
            start[i+delay] = curActive;
            end[i+forget] = curActive;
            total += curActive - end[i];
            total %= MOD;
        }
        return ((total+MOD) % MOD);
    }
};