class Solution {
public:
    int smallestRepunitDivByK(int k) {
        vector<bool> v(k+1, false);
        int cur = 1, ans = 1;
        while (true) {
            cur %= k;
            if (cur == 0) {
                return ans;
            } else if (v[cur]) {
                return -1;
            } else {
                v[cur] = true;
            }
            cur *= 10;
            cur++;
            ans++;
        }
        return -1;
    }
};