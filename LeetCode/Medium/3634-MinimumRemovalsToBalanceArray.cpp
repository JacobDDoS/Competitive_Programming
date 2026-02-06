class Solution {
public:
    int minRemoval(vector<int>& nums, int k) {
        sort(nums.begin(), nums.end());
        int ans = nums.size()-1;
        for (int i=0;i<nums.size();i++) {
            ans = min(ans, i+(int)(nums.size()-(upper_bound(nums.begin(), nums.end(), k*(long long)nums[i])-nums.begin())));
        }
        return ans;
    }
};