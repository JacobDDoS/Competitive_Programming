class Solution {
public:
    vector<int> pivotArray(vector<int>& nums, int pivot) {
        int cnt = 0, ptr = 0;
        vector<int> ans(nums.size(), 0);
        for (int i : nums) {
            if (i == pivot) {
                cnt++;
            } else if (i < pivot) {
                ans[ptr++] = i;
            }
        }
        for (int i=0;i<cnt;i++) ans[ptr++] = pivot;
        for (int i : nums) if (i > pivot) ans[ptr++] = i;
        return ans;
    }
};