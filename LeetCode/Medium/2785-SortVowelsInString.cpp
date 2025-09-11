class Solution {
public:
    string sortVowels(string s) {
        vector<char> chars; 
        vector<int> pos; 
        for (int i=0;i<s.size();i++) {
            char c = tolower(s[i]);
            if (c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u') {
                chars.push_back(s[i]);
                pos.push_back(i);
            }
        }
        sort(chars.begin(), chars.end());
        for (int i=0;i<chars.size();i++) {
            s[pos[i]] = chars[i];
        }
        return s;
    }
};