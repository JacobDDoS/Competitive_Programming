class Solution {
public:
    int numSpecial(vector<vector<int>>& mat) {
        vector<int> rowCnt(mat.size(), 0), colCnt(mat[0].size(), 0);
        for (int r=0;r<mat.size();r++) {
            for (int c=0;c<mat[0].size();c++) {
                if (mat[r][c]) {
                    rowCnt[r]++;
                    colCnt[c]++;
                }
            }
        }
        int ans = 0;
        for (int r=0;r<mat.size();r++) {
            for (int c=0;c<mat[0].size();c++) {
                if (mat[r][c]) {
                    ans += (rowCnt[r] == 1 && colCnt[c] == 1);
                }
            }
        }
        return ans;
    }
};