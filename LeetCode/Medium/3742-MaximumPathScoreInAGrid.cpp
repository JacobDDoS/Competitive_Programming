class Solution {
public:
    int maxPathScore(vector<vector<int>>& grid, int k) {
        if (k > 399) k = 399;
        int m = (int)grid.size(), n = (int)(grid[0].size());
        vector<vector<vector<int>>> dp(m, vector<vector<int>>(n, vector<int>(k+1,-1)));
        
        if (grid[0][0] == 0) {
            dp[0][0][0] = 0;
        } else {
            dp[0][0][1] = grid[0][0];
        }
        for (int r=0;r<m;r++) {
            for (int c=0;c<n;c++) {
                for (int curK=0;curK<=k;curK++) {
                    if (dp[r][c][curK] == -1) continue;
                    // move right
                    if (r+1 != m && curK+!(!grid[r+1][c]) <= k) {
                        dp[r+1][c][curK+!(!grid[r+1][c])] = max(dp[r][c][curK]+grid[r+1][c], dp[r+1][c][curK+!(!grid[r+1][c])]);
                    }
                    // move down
                    if (c+1 != n && curK+!(!grid[r][c+1]) <= k) {
                        dp[r][c+1][curK+!(!grid[r][c+1])] = max(dp[r][c][curK]+grid[r][c+1], dp[r][c+1][curK+!(!grid[r][c+1])]);
                    }
                }
            }
        }

        int ans = -1;
        for (int i=0;i<=k;i++) {
            ans = max(ans, dp[m-1][n-1][i]);
        }

        return ans;
    }
};