#include <bits/stdc++.h> 
using namespace std;

class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        int best = 999;
        int index = -1;
        for (int i=nums.size()-2;i>=0;i--) {
            for (int j=i+1;j<nums.size();j++) {
                if (nums[j] > nums[i] && nums[j] < best) {
                    best = nums[j];
                    index = j;
                }
            }
            if (index != -1) {
                swap(nums[i], nums[index]);
                sort(nums.begin()+i+1, nums.end());
                return;
            }
        }
        reverse(nums.begin(), nums.end());
    }
};