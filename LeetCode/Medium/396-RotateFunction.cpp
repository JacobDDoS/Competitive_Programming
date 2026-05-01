class Solution {
public:
    int maxRotateFunction(vector<int>& nums) {
        int sum = 0, ans = INT_MIN, cur = 0, n = (int)nums.size();
        for (int i=0;i<n;i++) {
            cur += nums[i] * i;
            sum += nums[i];
        }

        ans = max(ans, cur);
        for (int i=n-1;i>=1;i--) {
            cur += sum - nums[i]*n;
            ans = max(ans, cur);
        }
        return ans;
    }
};