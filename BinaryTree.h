#ifndef BINARYTREE_H
#define BINARYTREE_H
#include <iostream>
#include "ItemType.h"

using namespace std;
//Node struct
struct Node{
    //key
    ItemType key;
    //left and right nodes
    Node *left;
    Node *right;
};
//Binary Tree class
class BinaryTree{
    //root node
    Node *root;
    
public:
    //constructor to initialize tree
    BinaryTree();
    //destructor
    ~BinaryTree();
    //helps destructor;
    void destroy(Node*& node);
    //inserts item using recursion
    void insert(Node*& node, ItemType key);
    //inserts item
    void insertItem(ItemType key);
    //Gets predecessor
    void getPredecessor(Node* node, ItemType& data);
    //deletes item
    void deleteItem(ItemType key);
    //deletes item using recursion
    void deleteIt(Node*& node, ItemType item);
    //deletes Node
    void deleteNode(Node*& node);
    //helps retrieve
    void get(Node* node, ItemType& item, bool &found);
    //looks for item
    void retrieve(ItemType &item, bool &found);
    //helps pring out preOrder
    void pOrder(Node* node) const;
    //prints out tree in preorder
    void preOrder() const;
    //prints out tree inorder
    void inOrder() const;
    //helps print out inOrder
    void nOrder(Node *node) const;
    //helps print out postorder
    void oOrder(Node *node) const;
    //prints out tree postorder
    void postOrder() const;
    //returns length of BST
    int getLength() const;
    //helps get length
    int length(Node* node) const;
};
#endif
