class Solution
{
public:
    int mincostTickets(vector<int> &days, vector<int> &costs)
    {
        vector<int> cost(days.size() + 1, 0);
        for (int i = 1; i < cost.size(); i++)
        {
            int idxOf7DaysAgo = (lower_bound(days.begin(), days.end(), days[i - 1] - 6) - days.begin());
            int idxOf30DaysAgo = (lower_bound(days.begin(), days.end(), days[i - 1] - 29) - days.begin());
            cost[i] = min({cost[i - 1] + costs[0], cost[idxOf7DaysAgo] + costs[1], cost[idxOf30DaysAgo] + costs[2]});
        }
        return cost[days.size()];
    }
};