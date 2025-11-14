class Solution {
public:
    vector<vector<int>> rangeAddQueries(int n, vector<vector<int>>& queries) {
        vector<vector<int>> ans(n, vector<int>(n, 0));
        vector<vector<int>> prefix(n, vector<int>(n,0));
        for (vector<int>& query : queries) {
            for (int r=query[0];r<=query[2];r++) {
                prefix[r][query[1]]++;
            }

            if (query[3] != n-1) {
                for (int r=query[0];r<=query[2];r++) {
                    prefix[r][query[3]+1]--;
                }
            }
        }

        int cur = 0;
        for (int r=0;r<n;r++) {
            cur = 0;
            for (int c=0;c<n;c++) {
                cur += prefix[r][c];
                ans[r][c] = cur;
            }
        }
        return ans;
    }
};