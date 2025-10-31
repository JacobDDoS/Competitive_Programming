class Solution {
public:
    vector<int> getSneakyNumbers(vector<int>& nums) {
        vector<bool> v(nums.size()+2, false);
        vector<int> ans;
        for (int i : nums) {
            if (v[i]) ans.push_back(i);
            v[i] = true;
        }
        return ans;
    }
};