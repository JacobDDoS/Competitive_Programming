class Solution {
public:
    long long getDescentPeriods(vector<int>& prices) {
        long long ans = 0, cur = 1;
        for (int i=1;i<prices.size();i++) {
            if (prices[i] == prices[i-1] - 1) {
                cur++;
            } else {
                ans += cur * (cur-1) / 2;
                cur = 1;
            }
        }
        if (cur != 1) {
            ans += cur * (cur-1) / 2;
        }
        return ans + (long long)prices.size();
    }
};