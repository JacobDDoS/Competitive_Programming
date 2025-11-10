class Solution {
public:
    int clear(unordered_map<int, vector<int>>& mp, int num, set<int>& z) {
        int ans = 0, ptr = 0;
        sort(mp[num].begin(), mp[num].end());
        while (ptr < mp[num].size()) {
            auto nextZeroPtr = z.lower_bound(mp[num][ptr]);
            int nextZero;
            if (nextZeroPtr == z.end()) {
                nextZero = 999999999;
            } else {
                nextZero = *nextZeroPtr;
            }
            ans++;
            while (ptr < mp[num].size() && mp[num][ptr] < nextZero) {
                z.insert(mp[num][ptr]);
                ptr++;
            }
        }
        return ans;
    }
    int minOperations(vector<int>& nums) {
        unordered_map<int, vector<int>> mp;
        set<int> s, z;
        int ans = 0;
        for (int i=0;i<nums.size();i++) {
            if (nums[i] == 0) {
                z.insert(i);
            } else {
                s.insert(nums[i]);
                mp[nums[i]].push_back(i);
            }
        }
        for (auto num : s) {
            if (num != 0) {
                ans += clear(mp, num, z);
            }
        }
        return ans;
    }
};