class Solution {
public:
    int earliestFinishTime(vector<int>& landStartTime, vector<int>& landDuration, vector<int>& waterStartTime, vector<int>& waterDuration) {
        int ans = 99999999, lPtr = 0, wPtr = 0, firstL = 99999999, firstW = 99999999;
        for (int i=0;i<landStartTime.size();i++) firstL = min(firstL, landStartTime[i] + landDuration[i]);
        for (int i=0;i<waterStartTime.size();i++) firstW = min(firstW, waterStartTime[i] + waterDuration[i]);
        for (int i=0;i<landStartTime.size();i++) {
            if (landStartTime[i] > firstW) {
                ans = min(ans, landStartTime[i]+landDuration[i]);
            } else {
                ans = min(ans, firstW+landDuration[i]);
            }
        }
        for (int i=0;i<waterStartTime.size();i++) {
            if (waterStartTime[i] > firstL) {
                ans = min(ans, waterStartTime[i]+waterDuration[i]);
            } else {
                ans = min(ans, firstL+waterDuration[i]);
            }
        }
        return ans;
    }
};