//
// Created by viewsharp on 05.05.18.
//

#ifndef LAB_2_4_TREAP_H
#define LAB_2_4_TREAP_H

#include <queue>
#include <memory>

namespace treap {

// Узел двоичного дерева
    template<class T1, class T2>
    struct CNode {
        T1 key;
        T2 priority;
        CNode *left{nullptr}; // NULL, если нет.
        CNode *right{nullptr}; // NULL, если нет.
    };


    template<class T1, class T2>
    class Treap {
    public:
        Treap() :
                root(nullptr) {}

        ~Treap() {
            if (not root)
                return;

            std::queue<CNode<T1, T2> *> queue;
            queue.push(root);

            while (!queue.empty()) {
                CNode<T1, T2> *node = queue.front();
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

        void insert(T1 key, T2 priority) {

            auto autoPtr = std::make_unique<T1>();

            CNode<T1, T2> **node = &root;

            while (*node) {
                if ((*node)->priority < priority) {
                    CNode<T1, T2> *leftNode;
                    CNode<T1, T2> *rightNode;
                    split(*node, key, leftNode, rightNode);

                    *node = new CNode<T1, T2>;
                    (*node)->key = key;
                    (*node)->priority = priority;
                    (*node)->left = leftNode;
                    (*node)->right = rightNode;

                    return;
                }

                if ((*node)->key > key) {
                    node = &(*node)->left;
                } else {
                    node = &(*node)->right;
                }
            }

            *node = new CNode<T1, T2>;
            (*node)->key = key;
            (*node)->priority = priority;
        }

        unsigned long width() {
            if (not root)
                return 0;

            unsigned long result = 0;
            std::queue<std::pair<int, CNode<T1, T2> *>> queue;
            queue.push({1, root});

            int level = 0;

            while (!queue.empty()) {
                CNode<T1, T2> *node = queue.front().second;
                if (level != queue.front().first) {
                    if (queue.size() > result) {
                        result = queue.size();
                    }
                    level = queue.front().first;
                }
                queue.pop();

                if (node->left) {
                    queue.push({level + 1, node->left});
                }
                if (node->right) {
                    queue.push({level + 1, node->right});
                }
            }

            return result;
        }

    private:
        CNode<T1, T2> *root;

        void split(CNode<T1, T2> *currentNode, T1 key, CNode<T1, T2> *&left, CNode<T1, T2> *&right) {
            if (not currentNode) {
                left = nullptr;
                right = nullptr;
            } else if (currentNode->key <= key) {
                split(currentNode->right, key, currentNode->right, right);
                left = currentNode;
            } else {
                split(currentNode->left, key, left, currentNode->left);
                right = currentNode;
            }
        }
    };
}

#endif //LAB_2_4_TREAP_H
