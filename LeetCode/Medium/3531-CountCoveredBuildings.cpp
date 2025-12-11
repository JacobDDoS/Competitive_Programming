class Solution {
public:
    int countCoveredBuildings(int n, vector<vector<int>>& buildings) {
        vector<int> minY(n+1, 999999), maxY(n+1, -1), minX(n+1, 999999), maxX(n+1, -1);
        for (vector<int>& building : buildings) {
            minY[building[0]] = min(minY[building[0]], building[1]);
            maxY[building[0]] = max(maxY[building[0]], building[1]);

            minX[building[1]] = min(minX[building[1]], building[0]);
            maxX[building[1]] = max(maxX[building[1]], building[0]);
        }

        int ans = 0;
        for (vector<int>& building : buildings) {
            if (maxY[building[0]] > building[1] && minY[building[0]] < building[1] 
                && maxX[building[1]] > building[0] && minX[building[1]] < building[0]) {
                ans++;
            }
        }
        return ans;
    }
};