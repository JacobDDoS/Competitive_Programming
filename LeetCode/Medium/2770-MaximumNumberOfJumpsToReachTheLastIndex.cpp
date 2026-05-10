class Solution {
public:
    int maximumJumps(vector<int>& nums, int target) {
        vector<int> maxJumps(nums.size(), -1);
        maxJumps[nums.size()-1] = 0;
        for (int i=nums.size()-2;i>=0;i--) {
            for (int j=i+1;j<nums.size();j++) {
                if (abs(nums[j]-nums[i]) <= target && maxJumps[j] != -1) {
                    maxJumps[i] = max(maxJumps[i], 1+maxJumps[j]);
                }
            }
        }
        return maxJumps[0];
    }
};