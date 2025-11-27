class Solution {
public:
    long long maxSubarraySum(vector<int>& nums, int k) {
        vector<long long> sums(nums.size(), 0);
        for (int i=0;i<nums.size();i++) {
            sums[i] = nums[i] + (i != 0 ? sums[i-1] : 0);
        }

        vector<long long> mp(k, 0);
        vector<bool> exists(k, false);
        long long ans = LLONG_MIN;
        for (int i=0;i<nums.size();i++) {
            if ((i+1)%k==0) ans = max(ans, sums[i]);
            if (exists[i%k]) {
                ans = max(ans, sums[i]-mp[i%k]);
                mp[i%k] = min(mp[i%k], sums[i]);
            } else {
                exists[i%k] = true;
                mp[i%k] = sums[i];
            }
        }
        return ans;
    }
};