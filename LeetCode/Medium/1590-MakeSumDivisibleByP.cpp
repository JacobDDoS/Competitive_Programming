class Solution {
public:
    int minSubarray(vector<int>& nums, int p) {
        unordered_map<int, int> mp;
        unordered_map<int, bool> exists;
        vector<long long> sum(nums.size(), 0);
        long long totalSum = 0;
        int ans = 9999999;
        for (int i=0;i<nums.size();i++) {
            totalSum += nums[i];
            sum[i] = nums[i] + (i != 0 ? sum[i-1] : 0);
        }

        if (totalSum % p == 0) return 0;

        for (int i=0;i<nums.size();i++) {
            long long target = (p - ((totalSum - sum[i]) % p))%p;
            if (target == 0) {
                ans = min(ans, i+1);
            }

            if (exists[target]) {
                ans = min(ans, i-mp[target]);
            }

            exists[sum[i]%p] = true;
            mp[sum[i]%p] = i;
        }

        if (ans == 9999999 || ans == nums.size()) return -1;
        return ans;
    }
};