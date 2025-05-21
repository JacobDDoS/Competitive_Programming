class Solution
{
public:
    void setZeroes(vector<vector<int>> &matrix)
    {
        srand(time(NULL));
        int marker = (rand() % (1 << 5)) + (1 << 20);
        for (int row = 0; row < matrix.size(); row++)
        {
            bool hasZero = false;
            for (int col = 0; col < matrix[row].size(); col++)
            {
                if (matrix[row][col] == 0)
                {
                    hasZero = true;
                    break;
                }
            }
            if (hasZero)
            {
                for (int col = 0; col < matrix[row].size(); col++)
                {
                    if (matrix[row][col] == 0)
                    {
                        matrix[row][col] = marker;
                    }
                    else
                    {
                        matrix[row][col] = 0;
                    }
                }
            }
        }

        for (int row = 0; row < matrix.size(); row++)
        {
            for (int col = 0; col < matrix[row].size(); col++)
            {
                if (matrix[row][col] == marker)
                {
                    for (int k = 0; k < matrix.size(); k++)
                    {
                        matrix[k][col] = 0;
                    }
                }
            }
        }
    }
};