class Solution {
public:
    struct Node {
        vector<Node*> children;
        char val;

        Node(char c) : val(c) {}
    };
    vector<Node*> start{9, nullptr};
    int prefixLength(string num) {
        Node* ptr = nullptr;
        int cnt = 0;
        for (char c : num) {
            if (!ptr && start[c-'1']) {
                ptr = start[c-'1'];
                cnt++;
            } else if (!ptr) {
                return cnt;
            } else if (ptr) {
                bool flag = false;
                for (Node* n : ptr->children) {
                    if (n->val == c) {
                        flag = true;
                        ptr = n;
                        cnt++;
                    }
                }
                if (!flag) {
                    return cnt;
                }
            }
        }
        return cnt;
    }
    int longestCommonPrefix(vector<int>& arr1, vector<int>& arr2) {
        for (int num : arr1) {
            string str = to_string(num);
            Node* ptr = nullptr;
            for (char c : str) {
                if (!ptr && start[c-'1']) {
                    ptr = start[c-'1'];
                } else if (!ptr) {
                    ptr = new Node(c);
                    start[c-'1'] = ptr;
                } else if (ptr) {
                    bool flag = false;
                    for (Node* n : ptr->children) {
                        if (n->val == c) {
                            flag = true;
                            ptr = n;
                        }
                    }
                    if (!flag) {
                        Node* newPtr = new Node(c);
                        ptr->children.push_back(newPtr);
                        ptr = newPtr;
                    }
                }
            }
        }

        int ans = 0;
        for (int num : arr2) {
            ans = max(ans, prefixLength(to_string(num)));
        }
        return ans;
    }
};