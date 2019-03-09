#include "Node.h"
#include <stdio.h>
#include <iostream>

Node::Node()
{
    index = 0;
    data = 0;
    pLChild = NULL;
    pRChild = NULL;
    pParent = NULL;
}

Node *Node::SearchNode(int nodeIndex)
{
    if(this->index == nodeIndex){
        return this;
    }
    Node *temp = NULL;
    if(this->pLChild != NULL){
        if(this->pLChild->index == nodeIndex){
            return this->pLChild;
        }else{
            temp = this->pLChild->SearchNode(nodeIndex);
            if(temp != NULL){
                return temp;
            }
        }
    }
    if(this->pLChild != NULL){
        if(this->pRChild->index == nodeIndex){
            return this->pRChild;
        }else{
            temp = this->pRChild->SearchNode(nodeIndex);
            if(temp != NULL){
                return temp;
            }
        }
    }

    return NULL;
}

void Node::DeleteNode()
{
    if(this->pLChild != NULL){
        this->pLChild->DeleteNode();
    }

    if(this->pRChild != NULL){
        this->pRChild->DeleteNode();
    }

    if(this->pParent != NULL){
        if(this->pParent->pLChild == this){
            this->pParent->pLChild = NULL;
        }

        if(this->pParent->pRChild == this){
            this->pParent->pRChild = NULL;
        }
    }

    delete this;
}


// 前序
void Node::PreorderTraverse()
{
    std::cout << this->data << " ";
    if(this->pLChild != NULL){
        this->pLChild->PreorderTraverse();
    }
    if(this->pRChild != NULL){
        this->pRChild->PreorderTraverse();
    }
}
// 中序
void Node::InorderTraverse()
{
    if(this->pLChild != NULL){
        this->pLChild->InorderTraverse();
    }
    std::cout << this->data << " ";
    if(this->pRChild != NULL){
        this->pRChild->InorderTraverse();
    }
}


// 后序
void Node::PostorderTraverse()
{
    if(this->pLChild != NULL){
        this->pLChild->PostorderTraverse();
    }
    if(this->pRChild != NULL){
        this->pRChild->PostorderTraverse();
    }
    std::cout << this->data << " ";
}
