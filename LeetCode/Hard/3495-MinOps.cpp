class Solution
{
public:
    vector<long long> powersOfFour = {1};
    int idxAbove(int n)
    {
        return upper_bound(powersOfFour.begin(), powersOfFour.end(), n) - powersOfFour.begin();
    }
    long long calcQuery(long long a, long long b)
    {
        long long ans = 0, segEnd = 0;
        while (segEnd != b)
        {
            segEnd = min(b, powersOfFour[idxAbove(a)] - 1);
            ans += (segEnd - a + 1) * (idxAbove(a));
            a = powersOfFour[idxAbove(a)];
        }
        return (ans / 2) + (ans % 2);
    }
    long long minOperations(vector<vector<int>> &queries)
    {
        long long ans = 0, temp = 0;
        for (int i = 1; i < 19; i++)
        {
            powersOfFour.push_back(powersOfFour[i - 1] * 4);
        }
        for (int i = 0; i < queries.size(); i++)
        {
            ans += calcQuery(queries[i][0], queries[i][1]);
        }

        return ans;
    }
};