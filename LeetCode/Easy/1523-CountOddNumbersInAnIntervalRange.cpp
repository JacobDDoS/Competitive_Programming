class Solution {
public:
    int countOdds(int low, int high) {
        int ans = (low&1) + (high&1);
        if (low&1) low++;
        if (high&1) high--;
        ans += (high-low)/2;
        return ans;
    }
};