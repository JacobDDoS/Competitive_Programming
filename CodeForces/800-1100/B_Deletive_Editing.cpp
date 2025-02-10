#include <iostream>
#include <string>
using namespace std;

int main() {
    int t; cin>>t;

    while (t--) {
        string word; cin>>word;
        string look; cin>>look;

        char lastchar = look.back();
        char slastchar = look[look.length() - 2];

        bool foundlast = false;
        bool foundslast = false;
        bool repeated = false;
        for (int i = word.length() - 1; i < word.length(); i--){
            if (word[i] == lastchar) {
                foundlast = true;
            }
            if (word[i] == slastchar) {
                foundslast = true;
            }
            if ((word[i] == lastchar && foundlast == true) || (word[i] == slastchar && foundslast == true)) {
                repeated = true;
            }
        }

        if (foundlast == true && foundslast == true) {
            cout<<"YES"<<"\n";
            continue;
        }
        if (repeated == true) {
            cout<<"NO"<<"\n";
            continue;;
        }

    }
}