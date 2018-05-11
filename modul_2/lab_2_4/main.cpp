#include <iostream>
#include "Tree.h"

using namespace std;

int main() {

    int n;
    cin >> n;

    Tree<int> tree;
    int i;

    for (; n > 0; n--) {
        cin >> i;
        tree.insert(i);
    }

    tree.levelOrderPrint();

    return 0;
}