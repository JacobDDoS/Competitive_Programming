class Solution
{
public:
    bool isZeroArray(vector<int> &nums, vector<vector<int>> &queries)
    {
        map<int, int> start, end;
        for (int i = 0; i < queries.size(); i++)
        {
            start[queries[i][0]]++;
            end[queries[i][1]]++;
        }

        int curVal = 0;
        for (int i = 0; i < nums.size(); i++)
        {
            curVal += start[i];
            curVal -= end[i - 1];
            if (nums[i] > curVal)
            {
                return false;
            }
        }
        return true;
    }
};