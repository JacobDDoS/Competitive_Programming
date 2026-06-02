class Solution {
public:
    int earliestFinishTime(vector<int>& landStartTime, vector<int>& landDuration, vector<int>& waterStartTime, vector<int>& waterDuration) {
        int ans = 999999;
        for (int i=0;i<landStartTime.size();i++) {
            for (int j=0;j<waterStartTime.size();j++) {
                if (landStartTime[i] <= waterStartTime[j]) {
                    if (landStartTime[i] + landDuration[i] <= waterStartTime[j]) {
                        ans = min(ans, waterStartTime[j]+waterDuration[j]);
                    } else {
                        ans = min(ans, landStartTime[i]+landDuration[i]+waterDuration[j]);
                    }
                } else {
                    if (waterStartTime[j] + waterDuration[j] <= landStartTime[i]) {
                        ans = min(ans, landStartTime[i]+landDuration[i]);
                    } else {
                        ans = min(ans, waterStartTime[j]+waterDuration[j]+landDuration[i]);
                    }
                }
            }
        }
        return ans;
    }
};