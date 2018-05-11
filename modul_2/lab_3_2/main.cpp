#include <iostream>
#include "Tree.h"
#include "Treap.h"

using namespace std;

int main() {
    int n;

    cin >> n;

    tree::Tree<int> tree;
    treap::Treap<int, int> treap;

    int key;
    int priority;

    for (;n > 0; n--) {
        cin >> key >> priority;
        tree.insert(key);
        treap.insert(key, priority);
    }

    cout << (long)treap.width() - (long)tree.width();
}