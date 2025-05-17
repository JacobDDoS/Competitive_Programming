#include <bits/stdc++.h>
using namespace std;
void solve()
{
    long long n, m, l;
    cin >> n >> m >> l;
    vector<long long> nums(l);
    for (long long i = 0; i < l; i++)
    {
        cin >> nums[i];
    }
    map<long long, vector<long long>> mp;
    for (long long i = 0; i < m; i++)
    {
        long long a, b;
        cin >> a >> b;
        mp[a].push_back(b);
        mp[b].push_back(a);
    }

    vector<long long> evens(n + 1, -1);
    vector<long long> odds(n + 1, -1);

    queue<tuple<long long, long long, bool>> q;
    q.push({0, 1, true});

    while (!q.empty())
    {
        tuple<long long, long long, bool> next = q.front();
        q.pop();
        for (long long neighborNode : mp[get<1>(next)])
        {
            if (!(get<0>(next) & 1) && odds[neighborNode] == -1)
            {
                odds[neighborNode] = get<0>(next) + 1;
                q.push({odds[neighborNode], neighborNode, false});
            }
            else if ((get<0>(next) & 1) && evens[neighborNode] == -1)
            {
                evens[neighborNode] = get<0>(next) + 1;
                q.push({evens[neighborNode], neighborNode, true});
            }
        }
    }

    long long maxEven, maxOdd;
    long long smallestEven = 99999999, smallestOdd = 9999999;

    long long totalSum = 0;
    for (long long i = 0; i < l; i++)
    {
        totalSum += nums[i];
        if (nums[i] & 1)
        {
            smallestOdd = min(smallestOdd, nums[i]);
        }
        else
        {
            smallestEven = min(smallestEven, nums[i]);
        }
    }

    if (totalSum & 1)
    {
        maxOdd = totalSum;
        maxEven = totalSum - smallestOdd;
    }
    else
    {
        maxEven = totalSum;
        maxOdd = totalSum - smallestOdd;
    }

    string ans = "1";
    for (long long i = 2; i < n + 1; i++)
    {
        if (evens[i] != -1 && odds[i] != -1)
        {
            ans.push_back((evens[i] <= maxEven || odds[i] <= maxOdd) ? '1' : '0');
        }
        else if (odds[i] != -1)
        {
            ans.push_back((odds[i] <= maxOdd) ? '1' : '0');
        }
        else if (evens[i] != -1)
        {
            ans.push_back((evens[i] <= maxEven) ? '1' : '0');
        }
        else
        {
            ans.push_back('0');
        }
    }
    cout << ans << '\n';
}

int main()
{
    long long t;
    cin >> t;
    while (t--)
    {
        solve();
    }
}