class Solution {
public:
    int minMoves(vector<int>& nums, int limit) {
        vector<int> prefix(limit*2+1, 0), mp(limit*2+1, 0);
        for (int i=0;i<nums.size()/2;i++) {
            int sum = nums[i] + nums[nums.size()-i-1];
            mp[sum]++;
            int lb = sum - max(nums[i], nums[nums.size()-i-1]) + 1, ub = sum - min(nums[i], nums[nums.size()-i-1]) + limit;
            prefix[lb]--;
            if (ub+1 <= limit*2) prefix[ub+1]++;
        }

        int ans = nums.size()/2, cur = nums.size();
        for (int i=0;i<prefix.size();i++) {
            cur += prefix[i];
            ans = min(ans, cur-mp[i]);
        }

        return ans;
    }
};