class Solution {
public:
    int maximizeSquareHoleArea(int n, int m, vector<int>& hBars, vector<int>& vBars) {
        int ans = 1, adjH = 0, adjV = 0, tempH = 0, tempV = 0;
        sort(hBars.begin(), hBars.end());
        sort(vBars.begin(), vBars.end());
        for (int i=0;i<hBars.size();i++) {
            if (i == 0) {tempH = 1;}
            else if (hBars[i-1] == hBars[i]-1) {tempH++;}
            else {adjH = max(adjH, tempH); tempH = 1;}
        }
        adjH = max(adjH, tempH);

        for (int i=0;i<vBars.size();i++) {
            if (i == 0) {tempV = 1;}
            else if (vBars[i-1] == vBars[i]-1) {tempV++;}
            else {adjV = max(adjV, tempV); tempV = 1;}
        }
        adjV = max(adjV, tempV);

        ans = max(ans, (min(adjV, adjH)+1) * (min(adjV, adjH)+1));
        return ans;
    }
};