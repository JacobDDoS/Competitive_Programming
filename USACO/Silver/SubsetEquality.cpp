#include <bits/stdc++.h>
using namespace std;

bool isGood(string s, string t, char a, char b) {
    string newS = "";
    for (char& c : s) {
        if (c == a || c == b) {
            newS.push_back(c);
        }
    }

    string newT = "";
    for (auto& c : t) {
        if (c == a || c == b) {
            newT.push_back(c);
        }
    }

    return newS == newT && newS.size() == newT.size();
}

void solve() {
    string s, t;
    cin >> s >> t;
    int Q; cin >> Q;
    string alpha = "abcdefghijklmnopqr";

    vector<int> freqS(alpha.size());
    vector<int> freqT(alpha.size());

    for (int i=0;i<s.size();i++) {
        freqS[s[i]-'a']++;
    }

    for (int i=0;i<t.size();i++) {
        freqT[t[i]-'a']++;
    }

    bool doesPairWork[alpha.size()][alpha.size()];
    for (int i=0;i<alpha.size();i++) {
        for (int j=i+1;j<alpha.size();j++) {
            bool isGoodBool = isGood(s, t, alpha[i], alpha[j]);
            doesPairWork[i][j] = isGoodBool;
            doesPairWork[j][i] = isGoodBool;
        }
    }

    string ans = "";

    for (int i=0;i<Q;i++) {
        string qS; cin >> qS;
        bool isGood = true;
        int sSum = 0, tSum = 0;
        for (auto& c : qS) {
            sSum += freqS[c-'a'];
            tSum += freqT[c-'a'];
        }

        if (sSum != tSum) {
            isGood = false;
        }

        if (!isGood) {
            ans.push_back('N');
            continue;
        }
        for (int j=0;j<qS.size();j++) {
            for (int k=j+1;k<qS.size();k++) {
                if (!doesPairWork[qS[j]-'a'][qS[k]-'a']) {
                    isGood = false;
                    break;
                }
            }
            if (!isGood) {
                break;
            }
        }
        if (isGood) {
            ans += "Y";
        } else {
            ans += "N";
        }
    }
    cout << ans << '\n';
}

int main() {
    solve();
}