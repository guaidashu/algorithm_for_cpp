#include <iostream>
#include "Tree.h"

Tree::Tree()
{
    m_pRoot = new Node();
}

Node *Tree::SearchNode(int nodeIndex)
{
    return  m_pRoot->SearchNode(nodeIndex);
}

Tree::~Tree()
{
    // DeleteNode(0, NULL);
    m_pRoot->DeleteNode();
}

bool Tree::AddNode(int nodeIndex, int direction, Node *pNode)
{
    Node *temp = SearchNode(nodeIndex);
    if(temp == NULL){
        return false;
    }

    Node *node = new Node();
    if(node == NULL){
        return false;
    }
    node->index = pNode->index;
    node->data = pNode->data;
    node->pParent = temp;
    // 插入左子树
    if(direction == 0){
        temp->pLChild = node;
    }
    // 插入右子树
    if(direction == 1){
        temp->pRChild = node;
    }
    // 操作成功
    return true;
}

bool Tree::DeleteNode(int nodeIndex, Node *pNode)
{
    Node *temp = SearchNode(nodeIndex);
    if(temp == NULL){
        return false;
    }
    if(pNode != NULL){
        pNode->data = temp->data;
    }
    temp->DeleteNode();
    return true;
}


// 前序
void Tree::PreorderTraverse()
{
    std::cout << "前序遍历 ";
    m_pRoot->PreorderTraverse();
    std::cout << std::endl;
}
// 中序
void Tree::InorderTraverse()
{
    std::cout << "中序遍历 ";
    m_pRoot->InorderTraverse();
    std::cout << std::endl;
}
// 后序
void Tree::PostorderTraverse()
{
    std::cout << "后序遍历 ";
    m_pRoot->PostorderTraverse();
    std::cout << std::endl;
}



