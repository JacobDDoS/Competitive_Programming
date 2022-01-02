#include <bits/stdc++.h> 
using namespace std;

int maxArea(vector<int>& height) {
    int ans = -1;
    int leftPtr = 0;
    int rightPtr = height.size()-1;
    while (leftPtr < rightPtr) {
        ans = max(ans, (rightPtr-leftPtr)*min(height[rightPtr], height[leftPtr]));
        if (height[leftPtr] < height[rightPtr]) {
            leftPtr++;
        } else {
            rightPtr--;
        }
    }
    return ans;
}

int main() {
    vector<int> heightArr = {1,8,6,2,5,4,8,3,7};
    cout << maxArea(heightArr) << endl;
}