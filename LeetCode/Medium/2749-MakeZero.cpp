class Solution
{
public:
    int makeTheIntegerZero(int num1, int num2)
    {
        int cnt = 0;
        long long lnum1 = num1, lnum2 = num2;
        while (lnum1 >= lnum2)
        {
            cnt++;
            lnum1 -= lnum2;
            if (lnum1 >= cnt && __builtin_popcountll(lnum1) <= cnt)
            {
                return cnt;
            }
        }
        return -1;
    }
};