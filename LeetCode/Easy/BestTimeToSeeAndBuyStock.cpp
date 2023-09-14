class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int lowest = 999999, maxProfit = 0;
        for (int i=0;i<prices.size();i++) {
            lowest = std::min(lowest, prices[i]);
            maxProfit = std::max(maxProfit, (prices[i]-lowest));
        }
        return maxProfit;
    }
};