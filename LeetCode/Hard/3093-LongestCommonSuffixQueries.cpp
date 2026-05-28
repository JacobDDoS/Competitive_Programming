class Solution {
public:
    struct TrieNode {
        int smallestLength, stringIdx;
        TrieNode* next[26];
        TrieNode(int s, int idx) : smallestLength(s), stringIdx(idx) {
            for (int i=0;i<26;i++) {
                next[i] = nullptr;
            }
        }
    };
    void del(TrieNode* node) {
        for (int i=0;i<26;i++) {
            if (node->next[i]) del(node->next[i]);
        }
        delete node;
    }
    void util(string& word, int wordIdx, TrieNode* node) {
        if (node->smallestLength > (int)word.size()) {
            node->smallestLength = (int)word.size();
            node->stringIdx = wordIdx;
        } else if (node->smallestLength == (int)word.size()) {
            node->stringIdx = min(node->stringIdx, wordIdx);
        }
    }
    vector<int> stringIndices(vector<string>& wordsContainer, vector<string>& wordsQuery) {
        TrieNode* start[26];
        int smallestWordLength = wordsContainer[0].size(), smallestWordIndex = 0;
        for (int i=0;i<wordsContainer.size();i++) {
            TrieNode* ptr = nullptr;
            if (wordsContainer[i].size() < smallestWordLength) {
                smallestWordLength = wordsContainer[i].size();
                smallestWordIndex = i;
            }
            for (int j=wordsContainer[i].size()-1;j>=0;j--) {
                int charIdx = wordsContainer[i][j] - 'a';
                if (!ptr) {
                    if (start[charIdx]) {
                        util(wordsContainer[i], i, start[charIdx]);
                        ptr = start[charIdx];
                    } else {
                        ptr = new TrieNode(wordsContainer[i].size(), i);
                        start[charIdx] = ptr;
                    }
                } else {
                    if (!ptr->next[charIdx]) {
                        TrieNode* temp = new TrieNode(wordsContainer[i].size(), i);
                        ptr->next[charIdx] = temp;
                        ptr = ptr->next[charIdx];
                    } else {
                        util(wordsContainer[i], i, ptr->next[charIdx]);
                        ptr = ptr->next[charIdx];
                    }
                }
            }
        }

        vector<int> ans(wordsQuery.size(), -1);
        for (int i=0;i<wordsQuery.size();i++) {
            TrieNode* ptr = nullptr;
            for (int j=wordsQuery[i].size()-1;j>=0;j--) {
                int charIdx = wordsQuery[i][j] - 'a';
                if (!ptr) {
                    if (!start[charIdx]) {
                        ans[i] = smallestWordIndex;
                        break;
                    } else {
                        ptr = start[charIdx];
                    }
                } else {
                    if (!ptr->next[charIdx]) {
                        ans[i] = ptr->stringIdx;
                        break;
                    } else {
                        ptr = ptr->next[charIdx];
                    }
                }
            }
            if (ans[i] == -1) {
                ans[i] = ptr->stringIdx;
            }
        }
        
        for (int i=0;i<26;i++) {
            if (start[i]) del(start[i]);
        }

        return ans;
    }
};