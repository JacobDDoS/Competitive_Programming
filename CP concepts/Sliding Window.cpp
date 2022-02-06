#include <bits/stdc++.h>
using namespace std;

vector<int> maxSlidingWindow(vector<int>& nums, int k) {
    vector<int> ans;
    int l = 0, r = 0;
    deque<int> dq;
    while (r < nums.size()) {
        while (!dq.empty() && nums[dq.back()] < nums[r]) {
            dq.pop_back();
        } 
        dq.push_back(r);
        if (l > dq.front()) {
            dq.pop_front();
        }
        
        if (r-l+1 >= k) {
            ans.push_back(nums[dq.front()]);
            l++;
        }
        
        r++;
        
    }
    return ans;
}

int main() {
    vector<int> input = {1, 3, -1, -3, 5, 3, 6, 7};
    vector<int> result = maxSlidingWindow(input, 3);
    vector<int> expected = {3, 3, 5, 5, 6, 7};
    for (int i=0;i<expected.size();i++) {
        cout << "Expected: " << expected[i] << " Answered: " << result[i] << endl;
    }
}