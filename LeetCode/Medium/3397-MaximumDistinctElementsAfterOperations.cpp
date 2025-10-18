class Solution {
public:
    int maxDistinctElements(vector<int>& nums, int k) {
        sort(nums.begin(), nums.end());
        int ans = 1, prev = nums[0]-k;
        for (int i=1;i<nums.size();i++) {
            if (prev >= nums[i]-k && prev < nums[i]+k) {
                ans++;
                prev++;
            } else if (nums[i]-k > prev) {
                prev = nums[i]-k;
                ans++;
            }
        }
        return ans;
    }
};