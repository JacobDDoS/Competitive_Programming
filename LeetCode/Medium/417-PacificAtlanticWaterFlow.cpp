class Solution {
public:
    // -1->Neither,0->Unvisited,1->Pacific, 2->Atlantic, 3->Both
    vector<vector<int>> s;
    const int dir[4][2] = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};

    void dfs(const int m, const int n, const vector<vector<int>>& heights) {
        int ans = 0;
        if (s[m][n] == 0) {
            s[m][n] = -1;
            for (auto& d : dir) {
                int r = m+d[0], c=n+d[1];
                if (r == -1 || c == -1) {ans|=1;continue;}
                if (c == s[0].size() || r == s.size()) {ans|=2;continue;}
                if (s[r][c] == -1) {continue;}
                if (s[r][c] && heights[m][n] >= heights[r][c]) {ans|=s[r][c];continue;}
                if (heights[m][n] >= heights[r][c]) {
                    dfs(r, c, heights);
                    if (s[r][c] != -1) ans |= s[r][c];
                }
            }

            if (ans == 0) return;
            s[m][n] = ans;
            for (auto& d : dir) {
                int r = m+d[0], c=n+d[1];
                if (r == -1 || c == -1 || c == s[0].size() || r == s.size()) {continue;}
                if (heights[m][n] == heights[r][c] && s[m][n] > s[r][c]) {
                    s[r][c] = s[m][n];
                    dfs(r, c, heights);
                }
            }
        } else if (s[m][n] != -1) {
            for (auto& d : dir) {
                int r = m+d[0], c=n+d[1];
                if (r == -1 || c == -1 || c == s[0].size() || r == s.size()) {continue;}
                if (heights[m][n] == heights[r][c] && s[m][n] > s[r][c]) {
                    s[r][c] = s[m][n];
                    dfs(r, c, heights);
                }
            }
        }
    }

    vector<vector<int>> pacificAtlantic(vector<vector<int>>& heights) {
        vector<int> temp(heights[0].size(), 0);
        for (int m=0;m<heights.size();m++) {
            s.push_back(temp);
        }

        vector<vector<int>> ans;
        for (int m=0;m<heights.size();m++) {
            for (int n=0;n<heights[0].size();n++) {
                if (!s[m][n]) {
                    dfs(m, n, heights);
                }
                if (s[m][n] == 3) {
                    ans.push_back({m, n});
                }
            }
        }

        return ans;
    }
};