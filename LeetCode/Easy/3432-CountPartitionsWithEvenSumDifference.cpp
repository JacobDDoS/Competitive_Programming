class Solution {
public:
    int countPartitions(vector<int>& nums) {
        int totalSum = 0, curSum = 0, ans = 0;
        for (int i : nums) totalSum += i;
        for (int i=0;i<nums.size()-1;i++) {
            curSum += nums[i];
            if (!((abs((totalSum-curSum)-curSum))&1)) ans++;
        }
        return ans;
    }
};