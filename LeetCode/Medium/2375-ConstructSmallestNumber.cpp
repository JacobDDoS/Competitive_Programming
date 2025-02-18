#include <bits/stdc++.h>
using namespace std;

class Solution {
    public:
        string smallestNumber(string pattern) {
            string ans = "";
            for (char i='1';i<='1'+pattern.size();i++) {
                ans.push_back(i);
            }
    
            for (int i=0;i<pattern.size();i++) {
                if (pattern[i] == 'I') continue;
                for (int j=i;j>=0;j--) {
                    if (pattern[j] == 'D') {
                        swap(ans[j], ans[j+1]);
                    } else {
                        break;
                    }
                }
            }
            return ans;
        }
    };