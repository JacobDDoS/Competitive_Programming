class Solution {
public:
    long long maxMatrixSum(vector<vector<int>>& matrix) {
        int low = abs(matrix[0][0]), negCnt = 0;
        long long ans = 0;
        for (vector<int>& r : matrix) {
            for (int i: r) {
                if (i<0) negCnt++;
                low = min(low, abs(i));
                ans += abs(i);
            }
        }
        if (negCnt & 1) ans -= 2*low;
        return ans;
    }
};