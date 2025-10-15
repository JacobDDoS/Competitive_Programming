class Solution {
public:
    int maxIncreasingSubarrays(vector<int>& nums) {
        int prev = -1, cur = 1, ans = 1;
        for (int i=1;i<nums.size();i++) {
            if (nums[i] > nums[i-1]) {
                cur++;
            } else {
                if (prev != -1) ans = max(ans, min(prev, cur));
                ans = max(ans, cur/2);
                prev = cur;
                cur = 1;
            }
        }

        if (prev != -1) ans = max(ans, min(prev, cur));
        ans = max(ans, cur/2);

        return ans;
    }
};