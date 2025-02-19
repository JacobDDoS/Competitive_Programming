#include <bits/stdc++.h>
using namespace std;

class Solution {
    public:
        string getHappyString(int n, int k) {
            int totalCombinations = 3 * (1<<(n-1));
            if (k > totalCombinations) {
                return "";
            }
            string ans = "";
            vector<char> setChars = {'a', 'b', 'c'};
            ans.push_back(setChars[(k-1)/(totalCombinations/3)]);
            k -= ((k-1)/(totalCombinations/3)) * (1<<(n-1));
            totalCombinations /= 3;
            while (totalCombinations > 1) {
                bool isHighest = k > (totalCombinations/2);
                if (isHighest) {
                    k -= (totalCombinations/2);
                }
                totalCombinations /= 2;
                if (isHighest) {
                    for (int i=2;i>=0;i--) {
                        if (setChars[i] != ans[ans.size()-1]) {
                            ans.push_back(setChars[i]);
                            break;
                        }
                    }
                } else {
                    for (int i=0;i<3;i++) {
                        if (setChars[i] != ans[ans.size()-1]) {
                            ans.push_back(setChars[i]);
                            break;
                        }
                    }
                }
            }
            return ans;
        }
    };