#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int maxAscendingSum(vector<int>& nums) {
        int ans = 0;
        for (int i=0;i<nums.size();i++) {
            int curSum = nums[i];
            while (i+1<nums.size() && nums[i+1] > nums[i]) {
                i++;
                curSum += nums[i];
            }
            ans = max(ans, curSum);
        }
        return ans;
    }
};