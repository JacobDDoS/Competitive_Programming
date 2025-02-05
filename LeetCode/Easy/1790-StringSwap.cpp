#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool areAlmostEqual(string s1, string s2) {
        vector<int> indices;
        for (int i=0;i<s1.size();i++) {
            if (s1[i] != s2[i]) {
                indices.push_back(i);
            }
        }
        if (indices.size() > 2 || indices.size() == 1) return false;
        if (indices.size() == 0) return true;

        return (s2[indices[0]] == s1[indices[1]] && s2[indices[1]] == s1[indices[0]]);
    }
};