class Solution {
public:
    int specialTriplets(vector<int>& nums) {
        int MOD = 1000000007;
        unordered_map<int, vector<int>> mp;
        for (int i=0;i<nums.size();i++) {
            mp[nums[i]].push_back(i);
        }

        int ans = 0;
        for (int i=1;i<nums.size()-1;i++) {
            if (mp[nums[i]*2].size() >= 2) {
                int less = lower_bound(mp[nums[i]*2].begin(), mp[nums[i]*2].end(), i) - mp[nums[i]*2].begin();
                int greater = mp[nums[i]*2].size() - less - (nums[i] == 0);
                ans += ((long long)less*greater) % MOD;
                ans %= MOD;
            }
        }
        return ans;
    }
};