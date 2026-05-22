class Solution {
public:
    int search(vector<int>& nums, int target) {
        int cur = 0;
        for (int i=nums.size()/2;i>=1;i>>=2) {
            while (i+cur < nums.size() && nums[i+cur] > nums[cur]) cur += i;
        }
        auto first = find(nums.begin(), nums.begin()+cur+1, target);
        if (first != nums.begin()+cur+1) {
            return first-nums.begin();
        }
        auto second = find(nums.begin()+cur+1, nums.end(), target);
        if (second != nums.end()) {
            return second-nums.begin();
        }
        return -1;
    }
};