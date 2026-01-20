class Solution {
public:
    vector<int> minBitwiseArray(vector<int>& nums) {
        for (int i=0;i<nums.size();i++) {
            if (nums[i] == 2) {
                nums[i] = -1;
            } else {
                int x = 1;
                while (nums[i] & (1<<x)) x++;
                x--;
                nums[i] ^= (1<<x);
            }
        }
        return nums;
    }
};