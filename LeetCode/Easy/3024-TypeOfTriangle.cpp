class Solution
{
public:
    string triangleType(vector<int> &nums)
    {
        sort(nums.begin(), nums.end());
        int dup = 0;
        for (int i = 1; i < 3; i++)
        {
            if (nums[i] == nums[i - 1])
            {
                dup++;
            }
        }

        if (nums[2] >= nums[0] + nums[1])
        {
            return "none";
        }

        if (dup == 2)
        {
            return "equilateral";
        }
        else if (dup == 1)
        {
            return "isosceles";
        }
        else
        {
            return "scalene";
        }

        // Easy one today
        // The rain has picked up!
        // Anyways, have a good day everyone!
    }
};