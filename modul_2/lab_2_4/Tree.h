//
// Created by viewsharp on 05.05.18.
//

#ifndef LAB_2_4_TREE_H
#define LAB_2_4_TREE_H

#include <queue>
#include <iostream>

// Узел двоичного дерева
template<class T>
struct CNode {
    CNode(T &value) :
            data(value),
            left(nullptr),
            right(nullptr),
            parent(nullptr) {
    }

    CNode(T &value, CNode<T> *parent) :
            data(value),
            left(nullptr),
            right(nullptr),
            parent(parent) {
    }

    T data;
    CNode *left; // NULL, если нет.
    CNode *right; // NULL, если нет.
    CNode *parent; // NULL, если корень.
};


template<class T>
class Tree {
public:
    Tree() :
            root(nullptr) {}

    ~Tree() {
        if (not root)
            return;

        std::queue<CNode<T> *> queue;
        queue.push(root);

        while (!queue.empty()) {
            CNode<T> *node = queue.front();
            queue.pop();

            if (node->left) {
                queue.push(node->left);
            }
            if (node->right) {
                queue.push(node->right);
            }

            delete node;
        }
    }

    void insert(T value) {
        CNode<T> **node = &root;
        CNode<T> *lastNode = nullptr;

        while (*node) {
            lastNode = *node;
            if ((*node)->data > value) {
                node = &(*node)->left;
            } else {
                node = &(*node)->right;
            }
        }

        *node = new CNode<T>(value, lastNode);
    }

    void levelOrderPrint() {
        if (not root)
            return;

        std::queue<CNode<T> *> queue;
        queue.push(root);

        while (!queue.empty()) {
            CNode<T> *node = queue.front();
            queue.pop();

            std::cout << node->data << ' ';

            if (node->left) {
                queue.push(node->left);
            }
            if (node->right) {
                queue.push(node->right);
            }
        }
    }

private:
    CNode<T> *root;

};


#endif //LAB_2_4_TREE_H
