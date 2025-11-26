class Solution {
public:
    int MOD = 1'000'000'007;
    int numberOfPaths(vector<vector<int>>& grid, int k) {
        vector<vector<vector<int>>> nums(grid.size(), vector<vector<int>>(grid[0].size(), vector<int>(k, 0)));
        nums[0][0][grid[0][0]%k]++;
        for (int r=0;r<grid.size();r++) {
            for (int c=0;c<grid[0].size();c++) {
                for (int i=0;i<k;i++) {
                    if (c != grid[0].size()-1) {
                        nums[r][c+1][(i+grid[r][c+1])%k] += nums[r][c][i];
                        nums[r][c+1][(i+grid[r][c+1])%k] %= MOD;
                    }
                    if (r != grid.size()-1) {
                        nums[r+1][c][(i+grid[r+1][c])%k] += nums[r][c][i];
                        nums[r+1][c][(i+grid[r+1][c])%k] %= MOD;
                    }
                }
            }
        }
        return nums[grid.size()-1][grid[0].size()-1][0];
    }
};