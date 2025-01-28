#include <bits/stdc++.h>
using namespace std;

class Solution {
public:

    int dfs(int r, int c, vector<vector<int>>& grid, vector<vector<bool>>& visited) {
        if (visited[r][c] || grid[r][c] == 0) {
            return 0;
        }
        visited[r][c] = true;
        int sum = grid[r][c];

        if (r-1 >= 0) {
            sum+=dfs(r-1, c, grid, visited);
        }
        if (r+1 < grid.size()) {
            sum+=dfs(r+1, c, grid, visited);
        }
        if (c-1 >= 0) {
            sum+=dfs(r, c-1, grid, visited);
        }
        if (c+1 < grid[0].size()) {
            sum+=dfs(r, c+1, grid, visited);
        }
        return sum;
    }

    int findMaxFish(vector<vector<int>>& grid) {
        vector<vector<bool>> visited(grid.size());
        for (int r=0;r<grid.size();r++) {
            for (int c=0;c<grid[r].size();c++) {
                visited[r].push_back(false);
            }
        }
        int ans = 0;
        for (int r=0;r<grid.size();r++) {
            for (int c=0;c<grid[r].size();c++) {
                ans = max(ans, dfs(r, c, grid, visited));
            }
        }
        return ans;
    }
};