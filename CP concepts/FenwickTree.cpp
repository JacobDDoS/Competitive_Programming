#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

void add(int i, int valueToAdd, vector<int>& fenwickTree) {
    //Since i is 0-based, add one to convert to one-based
    i += 1;
    while (i < fenwickTree.size() && i > 0) {
        fenwickTree[i] += valueToAdd;
        i += i & -i;
    }
}

int query(int i, vector<int>& fenwickTree) {
    int returnVal = 0;
    while (i > 0) {
        returnVal += fenwickTree[i];
        i -= i & -i;
    }

    return returnVal;
}

void setFenwickTreeValue(int index, int val, vector<int>& values, vector<int>& fenwickTree) {
    int dif = val - values[index];
    values[index] = val;
    cout << "dif: " << dif << endl;
    add(index, dif, fenwickTree);
}

int main() {
    int n = 12;
    vector<int> elms;
    for (int i=1;i<=n;i++) {
        elms.push_back(i);
    }

    vector<int> prefixSum;
    int sum = 0;
    for (int i=0;i<elms.size();i++) {
        sum += elms[i];
        prefixSum.push_back(sum);
    }

    //Make Fenwick Tree
    vector<int> fenwickTree(n+1, 0);
    for (int i=0;i<n;i++) {
        add(i, elms[i], fenwickTree);
    }

    // setFenwickTreeValue(0, 5, elms, fenwickTree);

    setFenwickTreeValue(0, 2, elms, fenwickTree);
    setFenwickTreeValue(0, 5, elms, fenwickTree);
    setFenwickTreeValue(0, 3, elms, fenwickTree);

    cout << "Fenwick Tree:     ";
    for (int i=1;i<=n;i++) {
        cout << query(i, fenwickTree) << " ";
    }
    cout << endl;

    cout << "Prefix Sum Array: ";
    for (int& elm : prefixSum) {
        cout << elm << " ";
    }
    cout << endl;

}