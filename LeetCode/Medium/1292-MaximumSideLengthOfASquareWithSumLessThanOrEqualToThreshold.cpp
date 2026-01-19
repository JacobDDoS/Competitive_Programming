class Solution {
public:
    int maxSideLength(vector<vector<int>>& mat, int threshold) {
        for (int r=0;r<mat.size();r++) {
            for (int c=0;c<mat[0].size();c++) {
                mat[r][c] += (r!=0 ? mat[r-1][c] : 0) + (c!=0 ? mat[r][c-1] : 0) - ((r!=0&&c!=0) ? mat[r-1][c-1] : 0);
            }
        }

        int ans = 0;
        for (int r=0;r<mat.size();r++) {
            for (int c=0;c<mat[0].size();c++) {
                for (int s=ans;;s++) {
                    if (r + s >= mat.size() || c+s >= mat[0].size()) break;
                    int squareSum = mat[r+s][c+s] - (r!= 0 ? mat[r-1][c+s] : 0) - (c!=0 ? mat[r+s][c-1] : 0) + ((r!=0&&c!=0) ? mat[r-1][c-1] : 0);
                    if (squareSum <= threshold) ans = s+1;
                }
            }
        }
        return ans;        
    }
};