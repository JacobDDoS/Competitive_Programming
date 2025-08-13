class Solution
{
public:
    bool isPowerOfThree(int n)
    {
        if (n < 0)
        {
            return false;
        }
        double logResult = log(n) / log(3.0);
        if (abs(logResult - round(logResult)) <= 1e-10)
        {
            return true;
        }
        return false;
    }
};