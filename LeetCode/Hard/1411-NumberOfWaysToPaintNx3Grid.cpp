class Solution {
public:
    int MOD = 1000000007;
    int numOfWays(int n) {
        vector<long long> v(12, 1);
        for (int i=1;i<n;i++) {
            vector<long long> temp = v;
            temp[0] = (v[4] + v[5] + v[7] + v[8] + v[9]);
            temp[1] = (v[4] + v[6] + v[7] + v[8]);
            temp[2] = (v[4] + v[5] + v[7] + v[8] + v[11]);
            temp[3] = (v[5] + v[9] + v[10] + v[11]);
            temp[4] = (v[0] + v[1] + v[2] + v[10] + v[11]);
            temp[5] = (v[0] + v[2] + v[3] + v[10]);
            temp[6] = (v[1] + v[8] + v[9] + v[11]);
            temp[7] = (v[0] + v[1] + v[9] + v[10] + v[11]);
            temp[8] = (v[0] + v[1] + v[2] + v[6]);
            temp[9] = (v[0] + v[2] + v[3] + v[6] + v[7]);
            temp[10] = (v[3] + v[4] + v[5] + v[7]);
            temp[11] = (v[2] + v[3] + v[4] + v[6] + v[7]);
            for (int j=0;j<12;j++) temp[j] %= MOD;
            v = temp;
        }

        long long ans = 0;
        for (long long i : v) ans += i;
        return ans % MOD;
    }
};