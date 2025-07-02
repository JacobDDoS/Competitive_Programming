class Solution
{
public:
    long long MOD = 1000000007;
    int possibleStringCount(string word, int k)
    {
        int cnt = 0, dup = 0;
        long long total = 1, toSubtract = 0;
        vector<int> groups;
        for (int i = 1; i < word.size(); i++)
        {
            if (word[i] == word[i - 1])
            {
                dup++;
                cnt++;
            }
            else if (cnt)
            {
                groups.push_back(cnt);
                cnt = 0;
            }
        }
        if (cnt)
        {
            groups.push_back(cnt);
        }

        k -= (word.size() - dup);
        if (k > -1)
        {
            vector<vector<int>> dp(groups.size() + 1, vector<int>(k + 1, 0));
            vector<vector<int>> dpAdd(groups.size() + 1, vector<int>(k + 1, 0));
            dp[0][0] = 1;

            int curSum;
            for (int i = 0; i <= groups.size(); i++)
            {
                curSum = 0;
                for (int j = 0; j <= k; j++)
                {
                    curSum += dpAdd[i][j];
                    curSum %= MOD;

                    if (!(i == 0 && j == 0))
                    {
                        dp[i][j] = curSum;
                    }
                    if (j > k || i == groups.size())
                    {
                        continue;
                    }
                    dpAdd[i + 1][j] += dp[i][j];
                    dpAdd[i + 1][j] %= MOD;
                    if (j + groups[i] + 1 > k || i == groups.size())
                    {
                        continue;
                    }
                    dpAdd[i + 1][j + groups[i] + 1] -= dp[i][j];
                    dpAdd[i + 1][j + groups[i] + 1] %= MOD;
                }
            }

            for (int i = 0; i < k; i++)
            {
                toSubtract += dp[groups.size()][i];
            }
            toSubtract %= MOD;
        }

        for (int i = 0; i < groups.size(); i++)
        {
            total *= (groups[i] + 1);
            total %= MOD;
        }

        long long ans = total - toSubtract;
        return (ans + MOD) % MOD;
    }
};