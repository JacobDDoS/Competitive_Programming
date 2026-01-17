class Solution {
public:
    long long largestSquareArea(vector<vector<int>>& bottomLeft, vector<vector<int>>& topRight) {
        long long ans = 0;
        for (int i=0;i<bottomLeft.size();i++) {
            for (int j=i+1;j<bottomLeft.size();j++) {
                if (
                    (topRight[i][0] <= bottomLeft[j][0] || bottomLeft[i][0] >= topRight[j][0]) ||
                    (topRight[i][1] <= bottomLeft[j][1] || bottomLeft[i][1] >= topRight[j][1])  
                ) continue;

                int leftX = max(bottomLeft[i][0], bottomLeft[j][0]);
                int rightX = min(topRight[i][0], topRight[j][0]);
                int topY = min(topRight[i][1], topRight[j][1]);
                int bottomY = max(bottomLeft[i][1], bottomLeft[j][1]);
                long long side = min(rightX-leftX, topY-bottomY);
                ans = max(ans, side*side);
            }
        }
        return ans;
    }
};