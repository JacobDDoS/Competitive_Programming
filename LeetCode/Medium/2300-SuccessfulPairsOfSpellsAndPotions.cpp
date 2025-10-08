class Solution {
public:
    vector<int> successfulPairs(vector<int>& spells, vector<int>& potions, long long success) {
        sort(potions.begin(), potions.end());
        vector<int> ans(spells.size(), 0);
        for (int i=0;i<ans.size();i++) {
            long long target = success/spells[i] + (success % spells[i] != 0 ? 1 : 0);
            ans[i] = potions.size() - (lower_bound(potions.begin(), potions.end(), target) - potions.begin());
        }
        return ans;
    }
};