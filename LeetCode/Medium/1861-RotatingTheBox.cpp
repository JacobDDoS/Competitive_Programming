class Solution {
public:
    vector<vector<char>> rotateTheBox(vector<vector<char>>& boxGrid) {
        vector<vector<char>> ans(boxGrid[0].size(), vector<char>(boxGrid.size(), '.'));
        for (int r=0;r<boxGrid.size();r++) {
            int cnt = 0;
            for (int c=0;c<boxGrid[r].size();c++) {
                if (boxGrid[r][c] == '#') {
                    cnt++;
                } else if (boxGrid[r][c] == '*') {
                    int curCol = boxGrid.size()-r-1;
                    ans[c][curCol] = '*';
                    for (int j=c-1;cnt>0;j--) {
                        ans[j][curCol] = '#';
                        cnt--;
                    }
                }

                if (cnt && c == boxGrid[r].size()-1) {
                    int curCol = boxGrid.size()-r-1;
                    for (int j=c;cnt>0;j--) {
                        ans[j][curCol] = '#';
                        cnt--;
                    }
                }
            }
        }
        return ans;
    }
};