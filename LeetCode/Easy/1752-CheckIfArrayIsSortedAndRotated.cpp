class Solution {
public:
    bool check(vector<int>& nums) {
        bool flag = false;
        for (int i=1;i<nums.size();i++) {
            if (!flag) {
                if (nums[i] < nums[i-1]) {
                    if (nums[i] > nums[0]) return false;
                    flag = true;
                }
            } else {
                if (nums[i] < nums[i-1] || nums[i] > nums[0]) return false;
            }
        }
        return true;
    }
};