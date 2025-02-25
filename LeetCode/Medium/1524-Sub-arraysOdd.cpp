#include <bits/stdc++.h>
using namespace std;

class Solution {
    public:
        int numOfSubarrays(vector<int>& arr) {
           vector<int> dpEven(arr.size(), 0);
           vector<int> dpOdd(arr.size(), 0);
           if (arr[0]&1) {
            dpOdd[0] = 1;
           } else {
            dpEven[0] = 1;
           }
    
            int sum = arr[0]&1;
           for (int i=1;i<arr.size();i++) {
            if (arr[i] & 1) {
                dpOdd[i] = (dpEven[i-1]+1) % (1000000007);
                dpEven[i] = (dpOdd[i-1]);
            } else {
                dpOdd[i] = (dpOdd[i-1]);
                dpEven[i] = (dpEven[i-1]+1)%(1000000007);
            }
            sum += dpOdd[i];
            sum %= (1000000007);
           }
           return sum;
        }
    };