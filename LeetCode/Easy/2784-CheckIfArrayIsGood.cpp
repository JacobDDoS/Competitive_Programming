class Solution {
public:
    bool isGood(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        for (int i=0;i<(int)nums.size()-2;i++) {
            if (nums[i] != i+1) return false;
        }
        return (nums.size()>=2 && nums[nums.size()-2] == nums[nums.size()-1] && nums[nums.size()-1] == nums.size()-1);
    }
};