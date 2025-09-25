class Solution {
public:
    int minimumTotal(vector<vector<int>>& triangle) {
        for (int i=1;i<triangle.size();i++) {
            for (int j=0;j<triangle[i].size();j++) {
                int l = j-1, r=j;
                if (l != -1 && r != triangle[i-1].size()) {
                    triangle[i][j] += min(triangle[i-1][l], triangle[i-1][r]);
                } else if (l == -1) {
                    triangle[i][j] += triangle[i-1][r];
                } else {
                    triangle[i][j] += triangle[i-1][l];
                }
            }
        }

        int ans = 999999999;
        for (int i=0;i<triangle[triangle.size()-1].size();i++) {
            ans = min(ans, triangle[triangle.size()-1][i]);
        }
        return ans;
    }
};