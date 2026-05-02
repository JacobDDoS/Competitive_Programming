#include <bits/stdc++.h>
using namespace std;

typedef unsigned long long ull;
typedef long long ll;

int main()
{
    ll sumOfSquares = 0, squareOfSums = 0;
    for (int i=1;i<=100;i++) {
        sumOfSquares += i*i;
        squareOfSums += i;
    }
    squareOfSums *= squareOfSums;
    cout << "The difference between the sum of the squares of the first hundred numbers and the square of its sum is: " << squareOfSums - sumOfSquares << endl;
}