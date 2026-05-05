#include <bits/stdc++.h>
#include <boost/multiprecision/cpp_int.hpp>

using namespace std;
using namespace boost::multiprecision;

typedef unsigned long long ull;
typedef long long ll;

vector<vector<ll>> dp(201, vector<ll>(8, 0));
vector<int> coins = {1, 2, 5, 10, 20, 50, 100, 200};

int totalFunctionCalls = 0;

ll countWays(int remainingSum, int idx) {
    totalFunctionCalls++;
    if (remainingSum == 0) return 1;
    if (dp[remainingSum][idx] != 0) return dp[remainingSum][idx];
    ll ans = 0;
    for (int i=idx;i<coins.size();i++) {
        if (remainingSum >= coins[i]) {
            ans += countWays(remainingSum-coins[i], i);
        }
    }

    dp[remainingSum][idx] = ans;
    return ans;
}

int main()
{
    cout << "There are " << countWays(200, 0) << " ways 2 pounds can be made using any number of coins" << endl;
    // cout << "Total function calls: " << totalFunctionCalls << endl;
}