class Solution {
public:
    vector<int> leftRightDifference(vector<int>& nums) {
        int right = 0, left = 0;
        for (int a : nums) right+=a;
        vector<int> ans(nums.size(), 0);
        for (int i=0;i<nums.size();i++) {
            right -= nums[i];
            ans[i] = abs(right-left);
            left += nums[i];
        }
        return ans;
    }
};