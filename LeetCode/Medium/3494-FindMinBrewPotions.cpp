class Solution {
public:
    long long minTime(vector<int>& skill, vector<int>& mana) {
        vector<long long> potionSum(skill.size(), 0);
        for (int i=0;i<skill.size();i++) {
            potionSum[i] = skill[i] * mana[0] + (i != 0 ? potionSum[i-1] : 0);
        }
        for (int i=1;i<mana.size();i++) {
            long long tempSum = 0, curMax = 0;
            for (int j=0;j<skill.size();j++) {
                curMax = max(curMax, potionSum[j]-tempSum);
                tempSum += mana[i] * skill[j];
            }

            tempSum = 0;
            for (int j=0;j<potionSum.size();j++) {
                tempSum += mana[i] * skill[j];
                potionSum[j] = curMax + tempSum;
            }
        }
        return potionSum[skill.size()-1];
    }
};