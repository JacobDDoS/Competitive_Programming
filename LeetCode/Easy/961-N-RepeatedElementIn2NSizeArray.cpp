class Solution {
public:
    int repeatedNTimes(vector<int>& nums) {
        vector<bool> s(10001, false);
        for (int i : nums) {
            if (s[i]) return i;
            s[i] = true;
        }
        return -1;
    }
};