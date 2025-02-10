#include <bits/stdc++.h>
using namespace std;

class Solution {
    public: 
        string clearDigits(string s) {
            string ans = "";
            for (int i=0;i<s.size();i++) {
                if (s[i] < '0' || s[i] > '9') {
                    ans.push_back(s[i]);
                } else {
                    ans.pop_back();
                }
            }
            return ans;
        }
};