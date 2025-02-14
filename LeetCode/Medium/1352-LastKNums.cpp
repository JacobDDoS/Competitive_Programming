#include <bits/stdc++.h>
using namespace std;

class ProductOfNumbers {
    public:
        vector<int> nums;
        ProductOfNumbers() {
    
        }
        
        void add(int num) {
            nums.push_back(num);
        }
        
        int getProduct(int k) {
            long long product = nums[nums.size()-k];
            for (int i=nums.size()-1;i>nums.size()-k;i--) {
                product*=nums[i];
            }
            return (int)product;
        }
    };
    
    /**
     * Your ProductOfNumbers object will be instantiated and called as such:
     * ProductOfNumbers* obj = new ProductOfNumbers();
     * obj->add(num);
     * int param_2 = obj->getProduct(k);
     */