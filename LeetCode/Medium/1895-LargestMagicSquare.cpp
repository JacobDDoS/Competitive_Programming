class Solution {
public:
    int largestMagicSquare(vector<vector<int>>& grid) {
        vector<vector<int>> rowSum(grid.size(), vector<int>(grid[0].size(), 0)), colSum(grid.size(), vector<int>(grid[0].size(), 0)), lDiag(grid.size(), vector<int>(grid[0].size(), 0)), rDiag(grid.size(), vector<int>(grid[0].size(), 0));
        for (int r=0;r<grid.size();r++) {
            for (int c=0;c<grid[r].size();c++) {
                rowSum[r][c] = grid[r][c] + (c!=0 ? rowSum[r][c-1] : 0);
                colSum[r][c] = grid[r][c] + (r!=0 ? colSum[r-1][c] : 0);
                lDiag[r][c] = grid[r][c] + ((r!=0&&c!=0) ? lDiag[r-1][c-1] : 0);
                
            }
        }

        for (int r=grid.size()-1;r>=0;r--) {
            for (int c=grid[r].size()-1;c>=0;c--) {
                rDiag[r][c] = grid[r][c] + ((r!=grid.size()-1&&c!=0) ? rDiag[r+1][c-1] : 0); 
            }
        }

        int ans = 1;
        for (int r=0;r<grid.size();r++) {
            for (int c=0;c<grid[r].size();c++) {
                for (int k=ans;;k++) {
                    if (r+k >= grid.size() || c+k >= grid[0].size()) break;
                    bool flag = true;
                    int val = rowSum[r][c+k] - (c!=0 ? rowSum[r][c-1] : 0);
                    for (int t=0;t<=k;t++) {
                        if ((rowSum[r+t][c+k] - (c!=0 ? rowSum[r+t][c-1] : 0)) != val) {
                            flag = false;
                            break;
                        }
                    }
                    if (flag) {
                        for (int t=0;t<=k;t++) {
                            if ((colSum[r+k][c+t] - (r!=0 ? colSum[r-1][c+t] : 0)) != val) {
                                flag = false;
                                break;
                            }
                        }
                        if (lDiag[r+k][c+k] - ((r!=0 && c!=0) ? lDiag[r-1][c-1] : 0) != val) flag = false;
                        if (rDiag[r][c+k] - ((r+k+1 < grid.size() && c!=0) ? rDiag[r+k+1][c-1] : 0) != val) flag = false;
                    }

                    if (flag) ans=k+1;
                }
            }
        }

        return ans;
    }
};