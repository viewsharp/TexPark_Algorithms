#include <iostream>
#include "Tree.h"

using namespace std;

int main() {
    int n;
    cin >> n;

    Tree<int> tree;
    int value;
    int k;

    for (; n > 0; n--) {
        cin >> value >> k;
        if (value > 0) {
            tree.insert(value);
        } else {
            tree.remove(abs(value));
        }
        cout << tree.stat(k) << endl;
    }

    return 0;
}