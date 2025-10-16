class Solution {
public:
    int findSmallestInteger(vector<int>& nums, int value) {
        vector<int> v(value, 0);
        for (int num : nums) {
            v[(value+(num%value))%value]++;
        }
        int ans = 99999999;
        for (int i=0;i<value;i++) {
            ans = min(ans, i + v[i]*value);
        }
        return ans;
    }
};