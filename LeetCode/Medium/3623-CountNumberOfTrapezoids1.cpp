class Solution {
public:
    int MOD = 1000000007;
    int countTrapezoids(vector<vector<int>>& points) {
        unordered_map<int, int> mp;
        for (vector<int>& point : points) {
            mp[point[1]]++;
        }

        long long totalSides = 0, ans = 0;
        for (auto& pr : mp) {
            totalSides += ((long long)pr.second*(pr.second-1))/2;
        }

        for (auto& pr : mp) {
            long long sides = ((long long)pr.second*(pr.second-1))/2;
            totalSides -= sides;
            ans += sides * (totalSides) % MOD;
            ans %= MOD;
        }

        return ans;
    }
};