class Solution {
public:
    int longestBalanced(vector<int>& nums) {
        set<int> e, o;
        int ans = 0;
        for (int i=0;i<nums.size();i++) {
            e.clear(); o.clear();
            for (int j=i;j<nums.size();j++) {
                int num = nums[j];
                if (num & 1) {
                    o.insert(num);
                } else {
                    e.insert(num);
                }
                if (e.size() - o.size() == 0) {
                    ans = max(ans, j-i+1);
                }
            }
        }

        return ans;
    }
};