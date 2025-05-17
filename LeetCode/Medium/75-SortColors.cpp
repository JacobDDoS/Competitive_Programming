class Solution
{
public:
    void sortColors(vector<int> &nums)
    {
        int zPtr = 0, oPtr = 0;
        for (int i = 0; i < nums.size(); i++)
        {
            if (nums[i] == 0)
            {
                if (zPtr == i)
                {
                    zPtr++;
                    oPtr++;
                }
                else
                {
                    swap(nums[i], nums[zPtr]);
                    zPtr++;
                    if (nums[i] != 1)
                    {
                        oPtr++;
                    }
                    i--;
                }
            }
            else if (nums[i] == 1)
            {
                if (oPtr == i)
                {
                    oPtr++;
                }
                else
                {
                    swap(nums[i], nums[oPtr]);
                    oPtr++;
                    i--;
                }
            }
        }
    }
};