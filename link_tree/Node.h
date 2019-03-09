#ifndef NODE_H
#define NODE_H

class Node
{
public:
    Node();
    Node *SearchNode(int nodeIndex);
    void DeleteNode();
    int index;
    int data;
    Node *pLChild;
    Node *pRChild;
    Node *pParent;
    // 前序
    void PreorderTraverse();
    // 中序
    void InorderTraverse();
    // 后序
    void PostorderTraverse();
};

#endif
