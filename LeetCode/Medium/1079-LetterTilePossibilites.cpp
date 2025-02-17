#include <bits/stdc++.h>
using namespace std;

class Solution {
    public:
        int numPermutations(string tiles) {
            int fact = 1;
            map<char, int> mp;
            for (int i=1;i<=tiles.size();i++) {
                fact *= i;
                mp[tiles[i-1]]++;
            }
            for (auto& pr : mp) {
                int tempFact = 1;
                for (int i=1;i<=pr.second;i++) {
                    tempFact *= i;
                }
                fact /= tempFact;
            }
            return fact;
        }
        int numTilePossibilities(string tiles) {
            int ans = 0;
            map<string, bool> mp;
            string tempStr = "";
            for (int i=1;i<(1<<tiles.size());i++) {
                tempStr = "";
                for (int j=0;j<tiles.size();j++) {
                    if (i & (1<<j)) {
                        tempStr.push_back(tiles[j]);
                    }
                }
                sort(tempStr.begin(), tempStr.end());
                if (!mp[tempStr]) {
                    ans += numPermutations(tempStr);
                    mp[tempStr] = true;
                }
            }
            return ans;
        }
    };