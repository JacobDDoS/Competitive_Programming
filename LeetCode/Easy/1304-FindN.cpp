class Solution
{
public:
    vector<int> sumZero(int n)
    {
        vector<int> nums(n, 0);
        if (n == 1)
            return nums;
        int sum = 0;
        for (int i = 0; i < n - 1; i++)
        {
            nums[i] = i + 1;
            sum += i + 1;
        }
        nums[n - 1] = -sum;
        return nums;
    }
};