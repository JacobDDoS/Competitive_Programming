class Solution {
public:
    int MOD = 1000000007;

    // The following code is from GeeksForGeeks: https://www.geeksforgeeks.org/dsa/segment-tree-range-minimum-query/
    // A utility function to get minimum of two numbers 
    int minVal(int x, int y) { 
        return (x < y)? x: y; 
    } 

    int maxVal(int x, int y) {
        return (x < y)? y: x; 
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


    // For MAX ST:
    // A recursive function to get the
    // minimum value in a given range of array
    // st --> Pointer to segment tree 
    // index --> Index of current node in the tree
    // ss & se --> Starting and ending indexes 
    // qs & qe --> Starting and ending indexes of query range
    int RMxQUtil(vector<int> &st, int ss, int se, int qs, 
                                    int qe, int index) { 
        // If segment of this node is a part of given range
        // then return the min of the segment
        if (qs <= ss && qe >= se) 
            return st[index]; 

        // If segment of this node if outside the range
        if (se < qs || ss > qe) 
            return 0; 

        // If a part of this segment
        // overlaps with the given range 
        int mid = getMid(ss, se); 
        return maxVal(RMxQUtil(st, ss, mid, qs, qe, 2*index+1), 
                    RMxQUtil(st, mid+1, se, qs, qe, 2*index+2)); 
    } 

    // Return minimum of elements in range
    // from index qs to qe
    int RMxQ(vector<int> &st, int n, int qs, int qe) { 

        // Check for invalid input
        if (qs < 0 || qe > n-1 || qs > qe) { 
            cout<<"Invalid Input"; 
            return -1; 
        } 
        return RMxQUtil(st, 0, n-1, qs, qe, 0); 
    } 

    // A recursive function that constructs
    // Segment Tree for array[ss..se]. 
    int constructxSTUtil(vector<int> &arr, int ss, int se,
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
        st[si] = maxVal(constructxSTUtil(arr, ss, mid, st, si*2+1), 
                        constructxSTUtil(arr, mid+1, se, st, si*2+2)); 
        return st[si]; 
    } 

    // Function to construct segment tree 
    vector<int> constructxST(vector<int> &arr, int n) { 

        //Height of segment tree 
        int x = (int)(ceil(log2(n))); 

        // Maximum size of segment tree 
        int max_size = 2*(int)pow(2, x) - 1; 

        vector<int> st(max_size);

        // Fill the allocated memory st 
        constructxSTUtil(arr, 0, n-1, st, 0); 

        // Return the constructed segment tree 
        return st; 
    } 

    int countPartitions(vector<int>& nums, int k) {
        vector<int> pos(nums.size()+1, 0);
        vector<int> posSum(nums.size()+1, 0);
        pos[nums.size()] = 1;
        posSum[nums.size()] = 1;

        vector<int> minSegmentTree = constructST(nums, nums.size());
        vector<int> maxSegmentTree = constructxST(nums, nums.size());

        int maxIndex = nums.size()-1;
        for (int i=nums.size()-1;i>=0;i--) {
            int curFarthest = i;
            int j=(1<<13);
            while (j>=1) {
                if (curFarthest+j <= maxIndex) {
                    int minVal = RMQ(minSegmentTree, nums.size(), i, curFarthest+j);
                    int maxVal = RMxQ(maxSegmentTree, nums.size(), i, curFarthest+j);
                    if (maxVal - minVal <= k) {curFarthest += j;}
                    else {j>>=1;}
                } else {
                    j>>=1;
                }
            }
            maxIndex = curFarthest;
            pos[i] = posSum[i+1] - (curFarthest+2 <= nums.size() ? posSum[curFarthest+2] : 0);
            while (pos[i] < 0) pos[i] += MOD;
            pos[i] %= MOD;
            posSum[i] = pos[i] + posSum[i+1];
            posSum[i] %= MOD;
        }
        return pos[0];
    }
};