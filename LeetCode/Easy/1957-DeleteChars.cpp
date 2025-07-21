class Solution
{
public:
    string makeFancyString(string s)
    {
        string ans = "";
        for (int i = 0; i < s.size(); i++)
        {
            if (ans.size() < 2)
            {
                ans.push_back(s[i]);
            }
            else if (ans[ans.size() - 2] != ans[ans.size() - 1] || s[i] != ans[ans.size() - 1])
            {
                ans.push_back(s[i]);
            }
        }
        return ans;
    }
};