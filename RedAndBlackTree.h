#ifndef SDIZO1_REDANDBLACKTREE_H
#define SDIZO1_REDANDBLACKTREE_H


#include <iostream>

using namespace std;

struct Node {
    int data;
    Node *parent;
    Node *left;
    Node *right;
    int color;
};

typedef Node *NodePtr;

class RedAndBlackTree {
private:
    NodePtr root;
    NodePtr NIL;


    NodePtr searchTreeHelper(NodePtr node, int key);

    void deleteFix(NodePtr x);

    void rbTransplant(NodePtr u, NodePtr v);

    void deleteNodeHelper(NodePtr node, int key);

    void insertFix(NodePtr k);

    void printHelper(NodePtr ptr, int level);

    NodePtr minimum(NodePtr node);

    void leftRotate(NodePtr x);

    void rightRotate(NodePtr x);


public:
    int size;
    RedAndBlackTree();

    ~RedAndBlackTree();

    void insert(int key);

    void deleteNode(int data);

    void printTree();

    NodePtr searchTree(int k);
};

#endif //SDIZO1_REDANDBLACKTREE_H
