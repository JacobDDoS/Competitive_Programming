#include <bits/stdc++.h>
using namespace std;

class Solution {
public:

    int startOfChain = -1;

//dfs(i, favorite, nodeToDoubleId, nodeInDoubleToOccurrences, visited, maxCycle);
    int dfs(int curNode, vector<int>& favorite, vector<int>& nodeToDoubleId, unordered_map<int, int>& nodeInDoubleToOccurrences, vector<bool>& visited, vector<int>& doubleLengthFromNode, unordered_set<int>& inPlay) {
        int nextNode = favorite[curNode];
        visited[curNode] = true;

        // If it is in a double, ignore it!
        if (nodeToDoubleId[curNode] != -1) {
            return 0;
        }

        // If it leads exactly to a double
        if (nodeToDoubleId[nextNode] != -1) {
            doubleLengthFromNode[curNode] = doubleLengthFromNode[nextNode]+1;
            // cout << "curNode: " << curNode << " nextNode: " << nextNode << '\n';
            // cout << "doubleLengthFromNode[nextNode]: " << doubleLengthFromNode[nextNode] << '\n';
            // cout << "doubleLengthFromNode[curNode]: " << doubleLengthFromNode[curNode] << '\n';
            nodeInDoubleToOccurrences[nodeToDoubleId[nextNode]] = max(nodeInDoubleToOccurrences[nodeToDoubleId[nextNode]], doubleLengthFromNode[curNode]);
            nodeToDoubleId[curNode] = nodeToDoubleId[nextNode];
            return 0;
        }

        // If it last in a chain
        if (visited[nextNode] && inPlay.count(nextNode)) {
            startOfChain = nextNode;
            return 1;
        } else if (visited[nextNode]) {
            return 0;
        }



        inPlay.insert(curNode);

        // If it is in the middle

        int chainSize = dfs(nextNode, favorite, nodeToDoubleId, nodeInDoubleToOccurrences, visited, doubleLengthFromNode, inPlay);
        inPlay.erase(curNode);
        // If it is in middle of a chain
        if (chainSize) {
            if (curNode == startOfChain) {
                startOfChain = -1;
            } 
            // If the chain happens in front of current node
            else if (startOfChain == -1) {
                return chainSize;
            }
            return chainSize+1;
        }
        // If it is in middle of a path going to a double
        if (nodeToDoubleId[nextNode] != -1) {
            // cout << "curNode: " << curNode << " nextNode: " << nextNode << '\n';
            // cout << "doubleLengthFromNode[nextNode]: " << doubleLengthFromNode[nextNode] << '\n';
            doubleLengthFromNode[curNode] = doubleLengthFromNode[nextNode]+1;
            nodeInDoubleToOccurrences[nodeToDoubleId[nextNode]] = max(nodeInDoubleToOccurrences[nodeToDoubleId[nextNode]], doubleLengthFromNode[curNode]);
            nodeToDoubleId[curNode] = nodeToDoubleId[nextNode];
        }

        return 0;
    }


    int maximumInvitations(vector<int>& favorite) {
        set<int> setOfDoubles;
        for (int i=0;i<favorite.size();i++) {
            if (favorite[favorite[i]] == i) {
                setOfDoubles.insert(i);
            }
        }

        vector<int> nodeToDoubleId(favorite.size());
        vector<int> doubleLengthFromNode(favorite.size());
        vector<bool> visited(favorite.size(), false);
        for (int i=0;i<favorite.size();i++) {
            nodeToDoubleId[i] = -1;
            doubleLengthFromNode[i] = 0;
        }
        unordered_map<int, int> nodeInDoubleToOccurrences;
        nodeInDoubleToOccurrences.reserve(setOfDoubles.size()*4);
        for (int nodeInDouble : setOfDoubles) {
            nodeInDoubleToOccurrences[nodeInDouble] = 1;
            nodeToDoubleId[nodeInDouble] = nodeInDouble;
            doubleLengthFromNode[nodeInDouble] = 1;
        }

        int maxCycle = 0;

        unordered_set<int> inPlay;
        for (int i=0;i<favorite.size();i++) {
            if (!visited[i]) {
                maxCycle = max(maxCycle, dfs(i, favorite, nodeToDoubleId, nodeInDoubleToOccurrences, visited, doubleLengthFromNode, inPlay));
            }
        }

        int sumOfDoubles = 0;
        for (int nodeInDouble : setOfDoubles) {
            // cout << "nodeInDouble: " << nodeInDouble << " Occurrences: " << nodeInDoubleToOccurrences[nodeInDouble] << '\n';
            sumOfDoubles += nodeInDoubleToOccurrences[nodeInDouble];
        }

        return max(maxCycle, sumOfDoubles);

    }
};

int main() {
    Solution solution;
    vector<int> favorite = {22,9,3,4,6,23,5,12,16,20,13,9,1,17,4,3,9,18,16,24,0,18,11,22,1};
    cout << solution.maximumInvitations(favorite) << '\n';
}