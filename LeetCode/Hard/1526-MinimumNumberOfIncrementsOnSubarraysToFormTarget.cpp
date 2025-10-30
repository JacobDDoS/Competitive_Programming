class Solution {
public:

    // The following minimum segment tree implementation was taken from GeeksForGeeks:
    //  https://www.geeksforgeeks.org/dsa/segment-tree-range-minimum-query/
    // A utility function to get minimum of two numbers 
    int minVal(int x, int y) { 
        return (x < y)? x: y; 
    } 

    // A utility function to get the 
    // middle index from corner indexes. 
    int getMid(int s, int e) { 
        return s + (e -s)/2; 
    } 

    // A recursive function to get the
    // minimum value in a given range of array
    // st --> Pointer to segment tree 
    // index --> Index of current node in the tree
    // ss & se --> Starting and ending indexes 
    // qs & qe --> Starting and ending indexes of query range
    int RMQUtil(vector<int> &st, int ss, int se, int qs, 
                                    int qe, int index) { 

        // If segment of this node is a part of given range
        // then return the min of the segment
        if (qs <= ss && qe >= se) 
            return st[index]; 

        // If segment of this node if outside the range
        if (se < qs || ss > qe) 
            return INT_MAX; 

        // If a part of this segment
        // overlaps with the given range 
        int mid = getMid(ss, se); 
        return minVal(RMQUtil(st, ss, mid, qs, qe, 2*index+1), 
                    RMQUtil(st, mid+1, se, qs, qe, 2*index+2)); 
    } 

    // Return minimum of elements in range
    // from index qs to qe
    int RMQ(vector<int> &st, int n, int qs, int qe) { 

        // Check for invalid input
        if (qs < 0 || qe > n-1 || qs > qe) { 
            cout<<"Invalid Input"; 
            return -1; 
        } 
        return RMQUtil(st, 0, n-1, qs, qe, 0); 
    } 

    // A recursive function that constructs
    // Segment Tree for array[ss..se]. 
    int constructSTUtil(vector<int> &arr, int ss, int se,
                                vector<int> &st, int si) {

        // If there is one element in array,
        // store it in current node of 
        // segment tree and return 
        if (ss == se) { 
            st[si] = arr[ss]; 
            return arr[ss]; 
        } 

        // If there are more than one elements, 
        // then recur for left and right subtrees 
        // and store the minimum of two values in this node 
        int mid = getMid(ss, se); 
        st[si] = minVal(constructSTUtil(arr, ss, mid, st, si*2+1), 
                        constructSTUtil(arr, mid+1, se, st, si*2+2)); 
        return st[si]; 
    } 

    // Function to construct segment tree 
    vector<int> constructST(vector<int> &arr, int n) { 

        //Height of segment tree 
        int x = (int)(ceil(log2(n))); 

        // Maximum size of segment tree 
        int max_size = 2*(int)pow(2, x) - 1; 

        vector<int> st(max_size);

        // Fill the allocated memory st 
        constructSTUtil(arr, 0, n-1, st, 0); 

        // Return the constructed segment tree 
        return st; 
    }


    // The following is my own code
    vector<int> minTree;
    vector<bool> satisfied;
    unordered_map<int, vector<int>> mp;

    int minOperations(vector<int>& target, int s, int e, int cur) {
        if (e < s || s < 0 || e > target.size()-1) return 0;
        if (e == s) return target[s]-cur;
        int minElm = RMQ(minTree, target.size(), s, e);
        int ans = minElm - cur;

        int arrStart = lower_bound(mp[minElm].begin(), mp[minElm].end(), s) - mp[minElm].begin();
        auto endPtr = upper_bound(mp[minElm].begin(), mp[minElm].end(), e);
        int arrEnd;
        if (endPtr == mp[minElm].end()) {
            arrEnd = mp[minElm].size();
        } else {
            arrEnd = endPtr - mp[minElm].begin();
        }
        ans += minOperations(target, s, mp[minElm][arrStart]-1, minElm);
        
        for (int j=arrStart;j<arrEnd-1;j++) {
            int a = mp[minElm][j], b = mp[minElm][j+1];
            ans += minOperations(target, a+1, b-1, minElm);
        }
        ans += minOperations(target, mp[minElm][arrEnd-1]+1, e, minElm);

        return ans;
    }

    int minNumberOperations(vector<int>& target) {
        minTree = constructST(target, target.size());
        satisfied = vector<bool>(target.size(), false);
        for (int i=0;i<target.size();i++) {
            mp[target[i]].push_back(i);
        }
        return minOperations(target, 0, target.size()-1, 0);
    }
};