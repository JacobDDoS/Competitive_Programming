class Solution {
public:
    int minimumPairRemoval(vector<int>& nums) {
        int fI = -1, minSum = 999999, ans = 0;
        bool flag = false;
        while (nums.size()>1) {
            fI = -1, minSum = 999999;
            flag = false;
            for (int i=0;i<nums.size()-1;i++) {
                if (nums[i] + nums[i+1] < minSum) {
                    minSum = nums[i] + nums[i+1];
                    fI = i;
                }
                if (nums[i+1] < nums[i]) flag = true;
            }
            if (!flag) return ans;
            ans++;
            vector<int> copy;
            for (int i=0;i<nums.size();i++) {
                if (i == fI) {
                    copy.push_back(nums[i]+nums[i+1]);
                    i++;
                } else {
                    copy.push_back(nums[i]);
                }
            }
            nums = copy;
        }
        return ans;
    }
};