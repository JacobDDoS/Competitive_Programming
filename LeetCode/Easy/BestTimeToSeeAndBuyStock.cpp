class Solution {
public:
    int maxProfit(vector<int>& prices) {
        vector<int> lowestAtEachPoint(prices.size());
        int lowest = 999999;
        for (int i=0;i<prices.size();i++) {
            lowest = std::min(lowest, prices[i]);
            lowestAtEachPoint[i] = lowest;
        }
        int maxProfit = 0;
        for (int i=0;i<prices.size();i++) {
            maxProfit = std::max(maxProfit, (prices[i]-lowestAtEachPoint[i]));
        }
        return maxProfit;
    }
};