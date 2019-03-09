#include <iostream>
#include "Tree.h"
using namespace std;

Tree::Tree(int size, int *pRoot)
{
    m_iSize = size;
    // 分配size个int大小的内存
    m_pTree = new int[size];
    for (int i = 0; i < size; i++) {
        m_pTree[i] = 0;
    }
    m_pTree[0] = *pRoot;
}

Tree::~Tree()
{
    delete []m_pTree;
    m_pTree = NULL;
}

int *Tree::SearchNode(int nodeIndex)
{
    if(nodeIndex < 0 || nodeIndex >= m_iSize){
        return NULL;
    }
    if(m_pTree[nodeIndex] == 0){
        return NULL;
    }
    return &m_pTree[nodeIndex];
}

bool Tree::AddNode(int nodeIndex, int direction, int *pNode)
{
    if(nodeIndex < 0 || nodeIndex >= m_iSize){
        return false;
    }
    if(m_pTree[nodeIndex] == 0){
        return false;                            
    }
    // 0 代表插入左节点 1 代表插入右节点
    if(direction == 0){
        // 如果超出了节点范围，无法插入
        if(nodeIndex * 2 + 1 >= m_iSize){
            return false;
        }
        // 如果该节点有值，无法插入
        if(m_pTree[nodeIndex * 2 + 1] != 0){
            return false;
        }
        m_pTree[nodeIndex * 2 + 1] = *pNode;
    }

    if(direction == 1){
        // 如果超出了节点范围，无法插入
        if(nodeIndex * 2 + 2 >= m_iSize){
            return false;
        }
        // 如果该节点有值，无法插入
        if(m_pTree[nodeIndex * 2 + 2] != 0){
            return false;
        }
        m_pTree[nodeIndex * 2 + 2] = *pNode;
    }
    return true;
}

bool Tree::DeleteNode(int nodeIndex, int *pNode){
    if(nodeIndex < 0 || nodeIndex >= m_iSize){
        return false;
    }
    if(m_pTree[nodeIndex] == 0){
        return false;
    }
    *pNode = m_pTree[nodeIndex];
    m_pTree[nodeIndex] = 0;
    return true;
}


void Tree::TreeTraverse()
{
    for(int i=0; i<m_iSize; i++){
        cout << m_pTree[i] << " ";
    }
}

