class Solution {
public:
    string to_lower(string str) {
        for (int i=0;i<str.size();i++) {
            str[i] = tolower(str[i]);
        }
        return str;
    }
    vector<string> spellchecker(vector<string>& wordlist, vector<string>& queries) {
        unordered_map<string, int> cap, vow, exact;
        for (int i=0;i<wordlist.size();i++) {
            exact[wordlist[i]] = i+1;
            string lowercaseWord = to_lower(wordlist[i]);
            if (cap[lowercaseWord] != 0) continue;
            cap[lowercaseWord] = i+1;
            for (int j=0;j<lowercaseWord.size();j++) {
                char c = lowercaseWord[j];
                if (c == 'e' || c == 'i' || c=='o' || c=='u') {
                    lowercaseWord[j] = 'a';
                }
            }
            if (vow[lowercaseWord] != 0) continue;
            vow[lowercaseWord] = i+1;
        }

        vector<string> ans(queries.size());
        for (int q=0;q<queries.size();q++) {
            if (exact[queries[q]] != 0) {
                ans[q] = wordlist[exact[queries[q]]-1];
                continue;
            }
            string lowQ = to_lower(queries[q]);
            if (cap[lowQ]) {
                ans[q] = wordlist[cap[lowQ]-1];
                continue;
            } 

            for (int i=0;i<lowQ.size();i++) {
                char c = lowQ[i];
                if (c=='e'||c=='i'||c=='o'||c=='u') {
                    lowQ[i] = 'a';
                }
            }
            if (vow[lowQ]) {
                ans[q] = wordlist[vow[lowQ]-1];
            }
        }
        return ans;
    }
};