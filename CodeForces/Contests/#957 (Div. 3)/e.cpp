#include <iostream>
#include <vector>
#include <set>
#include <map>
#include <cmath>

typedef long long ll;
typedef unsigned long long ull;

using namespace std;

pair<int, int> testA(int n, int a) {
    string nStr = to_string(n);
    int numDigitsInProduct = nStr.size() * a;
    int b;

    string test = "";
    for (int numDigits = 1;numDigits<=7;numDigits++) {
        test = "";
        b = numDigitsInProduct - numDigits;
        if (b < 1) {
            break;
        }
        for (int cnt=0;cnt<numDigits;cnt++) {
            test.push_back(nStr[cnt%nStr.size()]);
        }

        if (stoi(test) == (n*a - b)) {
            return make_pair(a, b);
        }
    }

    return make_pair(-1, -1);

}

void solve() {
    int n; cin >> n;
    vector<pair<int, int>> possi;
    for (int a=1;a<=10000;a++) {
        pair<int, int> posi = testA(n, a);
        if (posi.first != -1) {
            possi.push_back(posi);
        }
    }

    cout << possi.size() << endl;
    for (auto pr : possi) {
        cout << pr.first << " " << pr.second << '\n';
    }
}

int main() {
    int n;
    cin >> n;
    while (n--) {
        solve();
    }
}