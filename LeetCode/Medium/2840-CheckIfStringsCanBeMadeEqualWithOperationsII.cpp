class Solution {
public:
    bool checkStrings(string s1, string s2) {
        vector<int> v1(52, 0), v2(52, 0);
        bool f = true;
        for (char c : s1) {
            v1[c-'a'+f*26]++;
            f = !f;
        }
        f = true;
        for (char c : s2) {
            v1[c-'a'+f*26]--;
            f = !f;
        }
        for (int i=0;i<52;i++) {
            if (v1[i]) {
                return false;
            }
        }
        return true;
    }
};