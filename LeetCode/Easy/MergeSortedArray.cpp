class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        vector<int> nums;
        int p = 0; int p1 = 0;
        while (p < m && p1 < n) {
            if (nums1[p] < nums2[p1]) {
                nums.push_back(nums1[p]);
                p++;
            } else {
                nums.push_back(nums2[p1]);
                p1++;
            }
        }
        while (p < m) {
            nums.push_back(nums1[p]);
            p++;
        }
        while (p1 < n) {
            nums.push_back(nums2[p1]);
            p1++;
        }
        nums1 = nums;
    }
};