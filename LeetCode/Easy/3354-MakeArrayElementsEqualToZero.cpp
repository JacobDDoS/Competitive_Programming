class Solution {
public:
    int countValidSelections(vector<int>& nums) {
        int right = 0, left = 0, ans = 0;
        for (int& i : nums) right += i;
        for (int i=0;i<nums.size();i++) {
            int num = nums[i];
            if (num == 0 && right == left) ans+=2;
            else if (num == 0 && abs(right-left) == 1) ans++;
            right -= num;
            left += num;
        }
        return ans;
    }
};