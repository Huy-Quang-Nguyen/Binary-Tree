#include <iostream>
#include "ItemType.h"
#include "BinaryTree.h"

using namespace std;

BinaryTree::BinaryTree(){
    root = NULL;
}

BinaryTree::~BinaryTree(){
    destroy(this->root);
}

void BinaryTree::destroy(Node*& node){
    if(node != NULL){
        destroy(node->left);
        destroy(node->right);
        delete node;
    }
}

void BinaryTree::insertItem(ItemType key){
    insert(this->root,key);
}

void BinaryTree::insert(Node*& node, ItemType key){
    if (node == NULL){
        node = new Node;
        node->right = node->left = NULL;
        node->key = key;
    }
    else if(key.compareTo(node->key) == LESS){
        insert(node->left, key);
    }
    else if(key.compareTo(node->key) == GREATER){
        insert(node->right, key);
    }
    else{
        cout << "Item already in tree." << endl;
    }
}

void BinaryTree:: getPredecessor(Node* node, ItemType& data){
    while(node->right != NULL){
        node = node->right;
    }
    data = node->key;
}

void BinaryTree::deleteItem(ItemType key){
    if(this->root == NULL){
        cout << "List is empty" << endl;
    }
    else{
        deleteIt(this->root, key);
    }
}

void BinaryTree::deleteNode(Node*& node){
    ItemType data;
    Node* temp = NULL;
    if(node->left == NULL){
        node = node->right;
        delete temp;
    }
    else if(node->right == NULL){
        node = node->left;
        delete temp;
    }
    else{
        getPredecessor(node->left, data);
        node->key = data;
        deleteIt(node->left, data);
    }
}

void BinaryTree::deleteIt(Node*& node, ItemType key){
    if(key.compareTo(node->key) == LESS){
        deleteIt(node->left, key);
    }
    else if(key.compareTo(node->key) == GREATER){
        deleteIt(node->right, key);
    }
    else if(key.compareTo(node->key) == EQUAL){
        deleteNode(node);
    }
    else{
        cout << "Item not in Tree" << endl;
    }
}

void BinaryTree::retrieve(ItemType &item, bool &found){
    get(this->root, item, found);
}

void BinaryTree::get(Node* node, ItemType &item, bool &found){
    if(node == NULL){
        found = false;
    }
    else if(item.compareTo(node->key) == GREATER){
        get(node->right, item, found);
    }
    else if(item.compareTo(node->key) == LESS){
        get(node->left, item, found);
    }
    else if(node->key.compareTo(item) == EQUAL){
        found = true;
        cout << "Item found in tree." << endl;
    }
}

void BinaryTree::preOrder() const{
    pOrder(this->root);
    cout << "" << endl;
}

void BinaryTree::pOrder(Node* node) const{
    if(node != NULL){
        cout << node->key.getValue() << " ";
        pOrder(node->left);
        pOrder(node->right);
    }
}

void BinaryTree::inOrder() const{
    nOrder(this->root);
    cout << "" << endl;
}

void BinaryTree::nOrder(Node* node) const{
    if(node != NULL){
        nOrder(node->left);
        cout << node->key.getValue() << " ";
        nOrder(node->right);
    }
}

void BinaryTree::postOrder() const{
    oOrder(this->root);
    cout << "" << endl;
}

void BinaryTree::oOrder(Node* node) const{
    if(node != NULL){
        oOrder(node->left);
        oOrder(node->right);
        cout << node->key.getValue() << " ";
    }
}

int BinaryTree::getLength() const{
    return length(this->root);
}

int BinaryTree::length(Node* node) const{
    if(node == NULL){
        return 0;
    }
    else{
        return length(node->left) + length(node->right) + 1;
    }
}
