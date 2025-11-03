class Solution {
public:
    int minCost(string colors, vector<int>& neededTime) {
        int temp = neededTime[0], ans = 0;
        for (int i=1;i<colors.size();i++) {
            if (colors[i] == colors[i-1]) {
                ans += min(temp, neededTime[i]);
                temp = max(temp, neededTime[i]);
            } else {
                temp = neededTime[i];
            }
        }
        return ans;
    }
};