// Author: JacobDDoS 
// Date: 1/1/2022
// Problem: http://www.usaco.org/index.php?page=viewproblem2&cpid=1229

#include <bits/stdc++.h>
using namespace std;

typedef unsigned long long ull;
typedef long long ll;
typedef double long ld;

map<int, int> metals;
map<int, vector<int>> ingredientsForMetal;

int getOneUnitOf(int n) {
    if (metals[n]) {
        metals[n]--;
        return 1;
    }

    int returnVal = 1;
    for (int& ingredient : ingredientsForMetal[n]) {
        if (!getOneUnitOf(ingredient)) {
            return 0;
        }
    }

    return (returnVal && ingredientsForMetal[n].size() ? 1 : 0);

}

void solve() {
    int n; cin >> n;
    for (int i=1;i<=n;i++) {
        int num;
        cin >> num;
        metals[i] = num;
    }
    int k; cin >> k;
    
    for (int i=0;i<k;i++) {
        int metalToBeMade; cin >> metalToBeMade;
        int numberOfIngredients; cin >> numberOfIngredients;
        vector<int> ingredients(numberOfIngredients);
        for (int j=0;j<numberOfIngredients;j++) {
            cin >> ingredients[j];
        }
        sort(ingredients.begin(), ingredients.end(), greater<int>());
        ingredientsForMetal[metalToBeMade] = ingredients;
    }

    int ans = metals[n];
    metals[n]=0;
    while (getOneUnitOf(n)) {
        ans++;
    }

    cout << ans;
}

int main() {
    solve();
}