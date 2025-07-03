class Solution
{
public:
    char kthCharacter(int k)
    {
        string s1 = "a";
        while (s1.size() < k)
        {
            int n = s1.size();
            for (int i = 0; i < n; i++)
            {
                if (s1[i] == 'z')
                {
                    s1.push_back('a');
                }
                s1.push_back((char)(s1[i] + 1));
            }
        }
        return s1[k - 1];
    }
};