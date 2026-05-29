class Solution {
public:
    int sumOfDigits(int a) {
        int ans = 0;
        for (char c : to_string(a)) {
            ans += c-'0';
        }
        return ans;
    }
    int minElement(vector<int>& nums) {
        int ans = 99999999;
        for (int num : nums) {
            ans = min(ans, sumOfDigits(num));
        }
        return ans;
    }
};