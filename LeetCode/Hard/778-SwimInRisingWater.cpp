class Solution {
public:
    const vector<vector<int>> dir = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};
    bool bfs(vector<vector<bool>>& grid) {
        queue<pair<int, int>> q;
        vector<vector<bool>> visited(grid.size(), vector<bool>(grid.size(), false));
        if (!grid[0][0] || !grid[grid.size()-1][grid.size()-1]) return false; 
        q.push(make_pair(0, 0));
        visited[0][0] = true;
        while (!q.empty()) {
            auto [row, column] = q.front(); q.pop();
            if (row == grid.size()-1 && column == grid.size()-1) {
                return true;
            }
            for (auto d : dir) {
                int r = row+d[0], c=column+d[1];
                if (r == -1 || c == -1 || r == grid.size() || c == grid.size()) continue;
                if (grid[r][c] && !visited[r][c]) {
                    visited[r][c] = true;
                    q.push(make_pair(r, c));
                }
            }
        }
        return false;
    }
    int swimInWater(vector<vector<int>>& grid) {
        set<int> s;
        vector<int> nums;
        for (int i=0;i<grid.size();i++) {
            for (int j=0;j<grid[i].size();j++) {
                s.insert(grid[i][j]);
            }
        }
        for (int n : s) {
            nums.push_back(n);
        }
        sort(nums.begin(), nums.end());

        int low = 0, high = nums.size()-1;
        vector<vector<bool>> valid(grid.size(), vector<bool>(grid.size(), false));
        while (low < high) {
            int mid = (low+high)/2;
            for (int i=0;i<grid.size();i++) {
                for (int j=0;j<grid[i].size();j++) {
                    if (grid[i][j] <= nums[mid]) {
                        valid[i][j] = true;
                    } else {
                        valid[i][j] = false;
                    }
                }
            }
            bool good = bfs(valid);
            if (good) {
                high = mid;
            } else {
                low = mid+1;
            }
        }

        return nums[high];
    }
};