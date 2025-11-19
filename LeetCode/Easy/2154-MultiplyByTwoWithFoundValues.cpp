class Solution {
public:
    int findFinalValue(vector<int>& nums, int original) {
        vector<int> v(1001, 0);
        for (int& a : nums) v[a]++;
        while (original<=1000&&v[original]) original*=2;
        return original;
    }
};