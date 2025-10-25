class Solution {
public:
    int totalMoney(int n) {
        int d = n/7, r = n%7;
        int ans = 7*(7+d)*d/2 + (1+r+2*d)*r/2;
        return ans;
    }
};