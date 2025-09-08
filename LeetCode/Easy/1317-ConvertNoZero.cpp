class Solution
{
public:
    bool noZero(int i)
    {
        while (i > 0)
        {
            if (i % 10 == 0)
            {
                return false;
            }
            i /= 10;
        }
        return true;
    }
    vector<int> getNoZeroIntegers(int n)
    {
        vector<int> ans(2);
        for (int i = 1; i < n; i++)
        {
            if (noZero(i) && noZero(n - i))
            {
                ans[0] = i;
                ans[1] = n - i;
                break;
            }
        }
        return ans;
    }
};