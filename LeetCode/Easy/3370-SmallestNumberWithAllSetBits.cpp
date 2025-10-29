class Solution {
public:
    int smallestNumber(int n) {
        vector<int> nums;
        for (int i=1;i<12;i++) {
            nums.push_back((1<<i)-1);
        }
        return *lower_bound(nums.begin(), nums.end(), n);
    }
};