class Solution {
public:
    int maxFreqSum(string s) {
        map<char, int> v, c;
        for (int i=0;i<s.size();i++) {
            char ch = s[i];
            if (ch=='a'||ch=='e'||ch=='i'||ch=='o'||ch=='u') {
                v[ch]++;
            } else {
                c[ch]++;
            }
        }

        int cM = 0, vM = 0;
        for (auto pr : c) {
            cM = max(cM, pr.second);
        }
        for (auto pr : v) {
            vM = max(vM, pr.second);
        }
        return cM + vM;
    }
};