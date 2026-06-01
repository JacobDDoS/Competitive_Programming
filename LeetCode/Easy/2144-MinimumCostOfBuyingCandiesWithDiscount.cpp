class Solution {
public:
    int minimumCost(vector<int>& cost) {
        int ans = 0, temp = 0;
        sort(cost.begin(), cost.end());
        for (int i=cost.size()-1;i>=0;i--) {
            temp++;
            if (temp % 3 != 0) ans+=cost[i];
        }
        return ans;
    }
};