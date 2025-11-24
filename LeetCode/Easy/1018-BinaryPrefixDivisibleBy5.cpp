class Solution {
public:
    vector<bool> prefixesDivBy5(vector<int>& nums) {
        vector<bool> ans(nums.size(), false);
        int cur = 0;
        for (int i=0;i<nums.size();i++) {
            cur *= 2;
            cur += nums[i];
            cur %= 5;
            ans[i] = (cur%5==0);
        }
        return ans;
    }
};