#include <bits/stdc++.h>
using namespace std;

bool vectorsGood(vector<int> &occ, vector<int> &other)
{
    for (int i = 0; i < occ.size(); i++)
    {
        if (occ[i] > other[i])
        {
            return false;
        }
    }
    return true;
}

void solve()
{
    string s;
    cin >> s;
    vector<int> occ(26, 0);
    vector<int> occCopy(26, 0);
    vector<int> other(26, 0);
    for (int i = 0; i < s.size(); i++)
    {
        occ[s[i] - 'a']++;
    }
    int start = 0;
    for (int i = 0; i < s.size(); i++)
    {
        if (s[i] == s[s.size() - 1 - i])
        {
            occ[s[i] - 'a']--;
        }
    }

    occCopy = occ;
    // for (int i = 0; i < 26; i++)
    // {
    //     occCopy[i] = occ[i];
    // }

    for (int i = 0; i < s.size(); i++)
    {
        if (s[i] == s[s.size() - 1 - i])
        {
            start++;
        }
        else
        {
            break;
        }
    }

    int ans = 0, tempAns = 0;
    while (start != s.size())
    {
        occ[s[start] - 'a']--;
        other[s[start] - 'a']++;
        tempAns++;
        if (vectorsGood(occ, other))
        {
            ans = tempAns;
            break;
        }
        start++;
    }

    start = s.size() - 1, tempAns = 0;
    for (; start >= 0; start--)
    {
        if (s[start] != s[s.size() - 1 - start])
        {
            break;
        }
    }

    for (int i = 0; i < 26; i++)
    {
        other[i] = 0;
    }

    cout << "e: " << occCopy[4] << endl;
    while (start != -1)
    {
        occCopy[s[start] - 'a']--;
        other[s[start] - 'a']++;
        tempAns++;
        if (vectorsGood(occCopy, other))
        {
            ans = min(ans, tempAns);
            break;
        }
        start--;
    }

    cout << ans << '\n';
}

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        solve();
    }
}