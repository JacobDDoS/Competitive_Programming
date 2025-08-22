class Solution
{
public:
    int numSubmat(vector<vector<int>> &mat)
    {
        int ans = 0;
        for (int r = 0; r < mat.size(); r++)
        {
            for (int c = 0; c < mat[0].size(); c++)
            {
                int maxR = r + 1;
                for (int lc = c; lc >= 0; lc--)
                {
                    if (mat[r][lc] == 0)
                        break;
                    for (int hr = r; hr >= 0 && hr > r - maxR; hr--)
                    {
                        if (mat[hr][lc] == 0)
                        {
                            maxR = r - hr;
                        }
                    }
                    ans += maxR;
                }
            }
        }
        return ans;
    }
};