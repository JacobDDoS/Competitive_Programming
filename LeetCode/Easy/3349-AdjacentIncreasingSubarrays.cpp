class Solution {
public:
    bool hasIncreasingSubarrays(vector<int>& nums, int k) {
        vector<int> v(nums.size());
        int cnt = 0;
        for (int i=nums.size()-1;i>=0;i--) {
            cnt++;
            v[i] = cnt;
            if (i != 0 && nums[i] <= nums[i-1]) cnt = 0;
        }
        for (int i=0;i<v.size()-k;i++) {
            if (v[i] >= k && v[i+k] >= k) return true;
        }
        return false;
    }
};