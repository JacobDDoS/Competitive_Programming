#include <bits/stdc++.h>

using namespace std;

void solve() {
    int l, r; cin >> l >> r;
    int start = 0;
    int ans = 0;
    for (int i=30;i>=0;i--) {
        if ((r & (1<<i)) == (l & (1<<i))) {
            ans |= (r&(1<<i));
        } else {
            start = i;
            break;
        }
    }

    // cout << "start at beginning: " << start << endl;

    
    if ((r & (1<<(start-1))) == (l & (1<<(start-1)))) {
        ans |= ((r&(1<<(start-1)))<<1);
        ans |= (~r&(1<<(start-1)));
        start -= 2;
        // cout << "ans after same discovered: " << ans << endl;
    } else if ((r & (1<<(start-1))) == 1 && (l & (1<<(start-1))) == 0) {
        // cout << "3 0 case ran!\n";
        ans |= (1<<(start-1));
        start -= 2;
    } else {
        // 1 0 1
        // 0 1 1
        // 1 0 0
        if ((r & (1<<(start-2))) == 1 && (l & (1<<(start-2))) == 1) {
            ans |= (1<<start);
            start -= 3;
        } 
        // 1 0 1
        // 0 1 0
        // 0 1 1
        else if ((r & (1<<(start-2))) == 1 && (l & (1<<(start-2))) == 0) {
            ans |= (1<<(start-1));
            ans |= (1<<(start-2));
            start -= 3;
        }
        // 1 0 0
        // 0 1 0
        // 0 1 1
        else if ((r & (1<<(start-2))) == 0 && (l & (1<<(start-2))) == 0) {
            ans |= (1<<(start-1));
            ans |= (1<<(start-2));
            start -= 3;
        }
        // 1 0 0 0 ...
        // 0 1 1 1 ... 
        // Depends 
        else {

            // cout << "Special 3 case ran!\n";

            int startOfStart = start;
            start--;
            for (;start>=0;start--) {
                // cout << "first condition: " << ((r & (1<<start)) == 0) << endl;
                // cout << "second condition: " << ((l & (1<<start))) << " with number " << (l & (1<<start)) << " on l " << l << endl;
                if ((r & (1<<start)) == 0 && (l & (1<<start))) {
                    // cout << "Found another 0 1 pair!\n";
                    continue;
                } else {
                    break;
                }
            }

            // cout << "startOfStart at beginning: " << startOfStart << endl;
            // cout << "start at beginning of special case: " << start << endl;
            // 1 0 0 ... 1
            // 0 1 1 ... 1
            // 1 0 0 ... 0
            if ((r & (1<<start)) && (l & (1<<start))) {
                // cout << "special 3: 1 1 case ran!\n";
                ans |= (1<<startOfStart);
                start--;
            } 
            // 1 0 0 ... 0
            // 0 1 1 ... 0
            // 0 1 1 ... 1
            else if ((r & (1<<start)) == 0 && (l & (1<<start)) == 0) {
                // cout << "special 3: 0 0 case ran!\n";
                startOfStart--;
                for (;startOfStart>=start;startOfStart--) {
                    ans |= (1<<startOfStart);
                }
                start--;
            }
            // 1 0 0 ... 1
            // 0 1 1 ... 0
            // 1 0 0 ... 0
            else if ((r & (1<<start)) && (l & (1<<start)) == 0) {
                ans |= (1<<startOfStart);
                start--;
            }
                
        }
    }

    // cout << "start before finish: " << start << endl;
    // cout << "ans before finish: " << ans << endl;

    for (;start>=0;start--) {
        if ((r & (1<<start)) == (l & (1<<start))) {
            ans |= (~r&(1<<start));
        }
    }

    cout << l << " " << ans << " " << r << '\n';

    
}

int main() {
    int t; cin >> t;
    while (t--) {
        solve();
    }
}