vector<int> primesUnderThousand;
class Solution {
public:
    vector<bool> visited;
    vector<int> ans;
    forward_list<int> remainingPrimes;
    unordered_map<int, vector<int>> mp;
    unordered_map<int, bool> checkedPrime;

    void generatePrimesUnderThousand() {
        primesUnderThousand.push_back(2);
        for (int i=3;i<1'000;i+=2) {
            bool isPrime = true;
            int maxPrime = 1;
            for (int prime : primesUnderThousand) {
                if (i%prime == 0) {
                    isPrime = false;
                    break;
                } else if (prime*maxPrime > i) {
                    break;
                } else {
                    maxPrime = prime;
                }
            }
            if (isPrime) primesUnderThousand.push_back(i);
        }
    }

    void bfs(vector<int>& nums) {
        queue<int> q;
        q.push(nums.size()-1);
        visited[nums.size()-1] = true;
        while (ans[0] == 9999999) {
            int idx = q.front(); q.pop();

            if (!checkedPrime[nums[idx]]) {
                // Check remaining primes
                auto it = remainingPrimes.begin(), prev = remainingPrimes.begin();
                int sqrtStop = (int)sqrt(nums[idx])+1;
                while (it != remainingPrimes.end()) {
                    bool flag = false;
                    int prime = *it;
                    if (prime > sqrtStop) break;
                    if (nums[idx] % prime == 0) {
                        for (int newIdx : mp[prime]) {
                            if (!visited[newIdx]) {
                                ans[newIdx] = ans[idx]+1;
                                q.push(newIdx);
                                visited[newIdx] = true;
                                checkedPrime[prime] = true;
                            }
                        }

                        while (nums[idx] % prime == 0) nums[idx] /= prime;
                    } 
                    it++;
                }

                // What remains is 1 or prime
                if (nums[idx] != 1) {
                    for (int newIdx : mp[nums[idx]]) {
                        if (!visited[newIdx]) {
                            ans[newIdx] = ans[idx]+1;
                            q.push(newIdx);
                            visited[newIdx] = true;
                        }
                    }
                }
            }

            // Check out number to left
            if (idx != 0 && !visited[idx-1]) {
                ans[idx-1] = ans[idx]+1;
                q.push(idx-1);
                visited[idx-1] = true;
            }

            // Check out number to right
            if (idx != nums.size()-1 && !visited[idx+1]) {
                ans[idx+1] = ans[idx]+1;
                q.push(idx+1);
                visited[idx+1] = true;
            }
        }
    }

    int minJumps(vector<int>& nums) {
        ans = vector<int>(nums.size(), 9999999);
        visited = vector<bool>(nums.size(), false);
        ans[nums.size()-1] = 0;
        for (int i=0;i<nums.size();i++) {
            mp[nums[i]].push_back(i);
        }

        if (primesUnderThousand.size() == 0) generatePrimesUnderThousand();
        for (int i = primesUnderThousand.size()-1;i>=0;i--) {
            remainingPrimes.push_front(primesUnderThousand[i]);
        } 
        bfs(nums);
        return ans[0];
    }
};