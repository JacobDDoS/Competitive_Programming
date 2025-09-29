class Solution {
public:

    vector<vector<int>> dp;

    int minScoreTriangulation(vector<int>& values) {
        for (int i=0;i<values.size();i++) {
            vector<int> v(values.size(), 0);
            dp.push_back(v);
        }

        for (int start=values.size()-1;start>=0;start--) {
            for (int end=start+2;end<values.size();end++) {
                int best = 99999999;
                for (int k=start+1;k<end;k++) {
                    best = min(best, values[start]*values[end]*values[k] + dp[start][k] + dp[k][end]);
                }
                dp[start][end] = best;
            }
        }
        return dp[0][values.size()-1];
    }

};