// Author: JacobDDoS 
// Date: 11/20/22

#include <bits/stdc++.h>
using namespace std;

typedef unsigned long long ull;
typedef long long ll;
typedef double long ld;

void solve() {
    int n; cin >> n;
    vector<string> b(n);
    for (int i=0;i<n;i++) {
        cin >> b[i];
    }
    map<int, int> numOfTimesLookedAt;
    vector<pair<int, int>> bAdd;
    for (int i=0;i<n;i++) {
        int totalOnes = 0;
        for (int j=0;j<b[i].size();j++) {
            char c = b[i][j];
            if (c == '1') {
                numOfTimesLookedAt[j]++;
                totalOnes++;
            }
        }
        bAdd.push_back(make_pair(totalOnes, i));
    }

    sort(bAdd.begin(), bAdd.end());

    //Make all but the last one 

    set<int> allNums;
    for (int i=1;i<=n;i++) {
        allNums.insert(i);
    }

    map<int, set<int>> setA;
    map<set<int>, bool> doesSetAlreadyExist;

    for (int i=0;i<bAdd.size();i++) {
        string binString = b[bAdd[i].second];
        set<int> currentSet = allNums;
        for (int j=0;j<binString.size();j++) {
            if (binString[j] == '1') {
                set<int> intersect;
                set_intersection(currentSet.begin(), currentSet.end(), setA[j].begin(), setA[j].end(), inserter(intersect, intersect.begin()));
                currentSet = intersect;
            }
        }

        if (!doesSetAlreadyExist[currentSet]) {
            if (currentSet == allNums) {
                int numThatShouldExist = max(n-1, 1+numOfTimesLookedAt[bAdd[i].second]);
                set<int> maybe;
                set<int> bruh;
                bruh.insert(1);
                do {
                    for (int k=1;k<=allNums.size();k++) {
                        for (int l=0;l<numThatShouldExist;l++) {
                            maybe.insert(max((k+l)%(allNums.size()+1), bruh.size()));
                        }
                        if (doesSetAlreadyExist[maybe]) {
                            maybe.clear();
                        } else {
                            break;
                        }
                    }
                } while (maybe.empty());

                currentSet = maybe;
            }
            setA[bAdd[i].second] = currentSet;
            doesSetAlreadyExist[currentSet] = true;
        } else {
            for (auto num : currentSet) {
                set<int> copy = currentSet;
                copy.erase(num);

                if (!doesSetAlreadyExist[copy]) {
                    bool isGood = true;
                    for (int j=0;j<binString.size();j++) {
                        if (binString[j] == '0') {
                            if (setA[j].size() > 0 && includes(setA[j].begin(), setA[j].end(), copy.begin(), copy.end())) {
                                isGood = false;
                                break;
                            }
                        }
                    }
                    if (isGood) {
                        setA[bAdd[i].second] = copy;
                        doesSetAlreadyExist[copy] = true;
                        break;
                    }
                }
            }
        }

    }

    for (int i=0;i<n;i++) {
        cout << setA[i].size() << " ";
        for (auto num : setA[i]) {
            cout << num << " ";
        }
        cout << '\n';
    }

}

int main() {
    // freopen("input.in", "r", stdin);
    // freopen("output.out", "w", stdout);
    int n;
    cin >> n;
    while (n--) {
        solve();
    }
    //solve();
}