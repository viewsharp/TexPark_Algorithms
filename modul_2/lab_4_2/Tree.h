//
// Created by viewsharp on 05.05.18.
//

#ifndef LAB_2_4_TREE_H
#define LAB_2_4_TREE_H

#include <queue>
#include <utility>
#include <cassert>

// Узел двоичного дерева
template<class T>
class CNode {
public:
    explicit CNode(T &value) :
            data(value),
            left(nullptr),
            right(nullptr),
            _height(1),
            _size(1) {
    }

    T data;
    CNode *left; // NULL, если нет.
    CNode *right; // NULL, если нет.

    int bFactor() {
        return nodeHeight(right) - nodeHeight(left);
    }

    void fix() {
        fixHeight();
        fixSize();
    }

    unsigned int height() {
        return _height;
    }

    unsigned int size() {
        return _size;
    }

private:
    unsigned int _height;
    unsigned int _size;

    unsigned int nodeSize(CNode<T> *p) {
        return p ? p->size() : 0;
    }

    unsigned int fixSize() {
        _size = nodeSize(left) + nodeSize(right) + 1;
    }

    unsigned int nodeHeight(CNode<T> *p) {
        return p ? p->height() : 0;
    }

    void fixHeight() {
        unsigned int hl = nodeHeight(left);
        unsigned int hr = nodeHeight(right);
        _height = (hl > hr ? hl : hr) + 1;
    }
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
        insert(root, value);
    }

    T stat(unsigned int k) {
        assert(root);
        assert(k <= root->size());

        CNode<T> *node = root;
        unsigned int index = 0;

        while (node) {
            unsigned int leftSize = node->left ? node->left->size() : 0;
            if (k < index + leftSize) {
                node = node->left;
            } else if (k == index + leftSize) {
                return node->data;
            } else {
                node = node->right;
                index += leftSize + 1;
            }
        }
    }

    void remove(T value) {
        remove(root, value);
    }

private:
    CNode<T> *root;

    void rotateRight(CNode<T> *&p) // правый поворот вокруг p
    {
        CNode<T> *q = p->left;
        p->left = q->right;
        q->right = p;
        p->fix();
        q->fix();
        p = q;
    }

    void rotateLeft(CNode<T> *&q) // левый поворот вокруг q
    {
        CNode<T> *p = q->right;
        q->right = p->left;
        p->left = q;
        p->fix();
        q->fix();
        q = p;
    }

    void nodeBalance(CNode<T> *&p) // балансировка узла p
    {
        p->fix();
        if (p->bFactor() == 2) {
            if (p->right->bFactor() < 0)
                rotateRight(p->right);
            rotateLeft(p);
        }
        if (p->bFactor() == -2) {
            if (p->left->bFactor() > 0)
                rotateLeft(p->left);
            rotateRight(p);
        }
    }

    void remove(CNode<T> *&node, T value) {
        if (not node)
            return;

        if (node->data == value) { // Нашли, удаляем.
            removeNode(node);
            return;
        }
        if (node->data > value) {
            remove(node->left, value);
        } else {
            remove(node->right, value);
        }
        nodeBalance(node);
    };

    void removeNode(CNode<T> *&node) {
        if (not node->left) { // Если нет левого поддерева.
            CNode<T> *right = node->right;
            delete node;
            node = right;

        } else if (not node->right) { // Если нет правого поддерева.
            CNode<T> *left = node->left;
            delete node;
            node = left;

        } else {
            node->data = getRightChildMinNodeData(node, node->right);
        }
    }

    T getRightChildMinNodeData(CNode<T> *minParent, CNode<T> *min) {
        T data;

        if (min->left) {
            data = getRightChildMinNodeData(min, min->left);
        } else {
            data = min->data;

            if (minParent->left == min) {
                minParent->left = min->right;
            } else {
                minParent->right = min->right;
            }
            delete min;
        }

        nodeBalance(minParent);
        return data;
    }

    void insert(CNode<T> *&node, T value) // вставка ключа value в дерево с корнем node
    {
        if (not node) {
            node = new CNode<T>(value);
            return;
        }
        if (value < node->data)
            insert(node->left, value);
        else
            insert(node->right, value);
        nodeBalance(node);
    }
};

#endif //LAB_2_4_TREE_H
