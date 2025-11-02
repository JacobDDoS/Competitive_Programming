class Solution {
public:
    // dir:  0th bit->up, 1st bit->right, 2nd bit->down, 3rd bit->left
    void dfs(int row, int col, vector<vector<int>>& visited, int dir) {
        visited[row][col] |= dir;

        // up
        if ((dir & (1<<0)) && row != 0 && !(visited[row-1][col] & (1<<0))) {
            dfs(row-1, col, visited, (1<<0));
        }

        // right
        if ((dir & (1<<1)) && col != visited[0].size()-1 && !(visited[row][col+1] & (1<<1))) {
            dfs(row, col+1, visited, (1<<1));
        }

        // down
        if ((dir & (1<<2)) && row != visited.size()-1 && !(visited[row+1][col] & (1<<2))) {
            dfs(row+1, col, visited, (1<<2));
        }

        // left
        if ((dir & (1<<3)) && col != 0 && !(visited[row][col-1] & (1<<3))) {
            dfs(row, col-1, visited, (1<<3));
        }
    }

    int countUnguarded(int m, int n, vector<vector<int>>& guards, vector<vector<int>>& walls) {
        vector<vector<int>> visited(m, vector<int>(n, 0));
        for (vector<int>& wall : walls) {
            visited[wall[0]][wall[1]] = (1<<4)-1;
        }
        for (vector<int>& guard : guards) {
            visited[guard[0]][guard[1]] = (1<<4)-1;
        }
        for (vector<int>& guard : guards) {
            dfs(guard[0], guard[1], visited, (1<<4)-1);
        }
        int ans = 0;
        for (int i=0;i<m;i++) {
            for (int j=0;j<n;j++) {
                if (!visited[i][j]) ans++;
            }
        }
        return ans;
    }
};