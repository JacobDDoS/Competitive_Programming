#include <bits/stdc++.h>
using namespace std;

template <class T>
struct Node {
    T val;
    vector<Node<T>*> nextNodes;
    Node(T v) {
        val = v;
    }
};

int main() {
    cout << "Hello" << endl;
    Node<int>* n = new Node<int>(5);
    Node<string>* str = new Node<string>("Hello!");
    cout << (*n).val << endl;
    cout << (*str).val << endl;

    delete n, str;
}