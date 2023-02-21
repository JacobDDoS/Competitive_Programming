#include <bits/stdc++.h> 
using namespace std;

string simplifyPath(string path) {
    string ans = "/";
    vector<string> pathWords;
    string temp = "";
    for (int i=1;i<path.size();i++) {
        if (path[i] == '/' && temp.size() > 0) {
            if (temp != ".") {
                pathWords.push_back(temp);
            }
            temp = "";
        } else if (path[i] != '/') {
            temp.push_back(path[i]);
        }
    }
    if (temp.size() && temp != ".") {
        pathWords.push_back(temp);
    }
    bool isInFinalPath[pathWords.size()];
    for (int i=0;i<pathWords.size();i++) {
        isInFinalPath[i] = true;
    }
    for (int i=0;i<pathWords.size();i++) {
        if (pathWords[i] == "..") {
            isInFinalPath[i] = false;
            if (i != 0) {
                for (int j=i-1;j>=0;j--) {
                    if (isInFinalPath[j] == true) {
                        isInFinalPath[j] = false;
                        break;
                    }
                }
            }
        }
    }

    for (int i=0;i<pathWords.size();i++) {
        if (isInFinalPath[i]) {
            ans += pathWords[i];
            ans += "/";
        }
    }

    if (ans.size() > 1) {
        ans.pop_back();
    }
    return ans;
}

int main() {
    cout << simplifyPath("/.") << endl;
}