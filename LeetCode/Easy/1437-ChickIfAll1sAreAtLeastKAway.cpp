class Solution {
public:
    bool kLengthApart(vector<int>& nums, int k) {
        int cur = 0;
        bool flag = true;
        for (int i=0;i<nums.size();i++) {
            if (nums[i] == 0) {
                cur++;
            } else {
                if (flag) {
                    flag = false;
                } else if (cur < k) {
                    return false;
                }
                cur = 0;
            }
        }
        return true;
    }
};