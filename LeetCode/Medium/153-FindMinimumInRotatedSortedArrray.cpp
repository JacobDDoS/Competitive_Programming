class Solution {
public:
    int findMin(vector<int>& nums) {
       int cur = nums.size()-1;
       for (int i=nums.size()/2;i>=1;i/=2) {
            while (cur-i >= 0 && nums[cur-i] < nums[cur]) cur -= i;
       } 
       return nums[cur];
    }
};