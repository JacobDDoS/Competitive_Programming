class Solution {
public:
    int minOperations(vector<int>& nums) {
        int globalGCD = gcd(nums[0], nums[1]), ones = (nums[0] == 1);
        for (int i=1;i<nums.size();i++) {
            globalGCD = gcd(globalGCD, nums[i]);
            if (nums[i] == 1) ones++;
        }

        if (globalGCD != 1) {
            return -1;
        } else if (ones) {
            return (int)nums.size()-ones;
        } 

        set<int> cur;
        int globalMin = 999999, curMin = 999999;
        for (int i=0;i<nums.size();i++) {
            int j = i+1;
            curMin = 0;
            int curGCD = nums[i];
            while (j<(int)nums.size() && curGCD != 1) {
                curMin++;
                curGCD = gcd(curGCD, nums[j]);
                j++;
            }
            if (curGCD == 1) globalMin = min(globalMin, curMin);
        }

        return nums.size()-1+globalMin;
    }
};