#ifndef TREE_H
#define TREE_H

#include "Node.h"

class Tree
{
public:
    Tree();
    ~Tree();
    Node *SearchNode(int nodeIndex);
    bool AddNode(int nodeIndex, int direction, Node *pNode);
    bool DeleteNode(int nodeIndex, Node *pNode);
    // 前序
    void PreorderTraverse();
    // 中序
    void InorderTraverse();
    // 后序
    void PostorderTraverse();
private:
    Node *m_pRoot;
};

#endif
