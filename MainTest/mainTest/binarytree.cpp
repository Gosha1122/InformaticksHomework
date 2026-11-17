#include "binarytree.h"
#include <iostream>
using namespace std;

BinaryTree::Node::~Node()
{
    if(left != nullptr) delete left;
    if(right != nullptr) delete right;
}

bool BinaryTree::isEmpty()
{
    return(root == nullptr);
}

void BinaryTree::insert(int value)
{
    if(root == nullptr){
        root = new Node;
        root->count = 1;
        root->value = value;
        return;
    }
    insert(root, value);
}

void BinaryTree::erase(int value)
{
    if(isEmpty()) return;
    root = erase(root, value);
}

bool BinaryTree::contains(int value)
{
    if(isEmpty()) return false;
    return contains(root, value);
}

void BinaryTree::print()
{
    print(root);
}

int BinaryTree::size()
{
    if(isEmpty()) return 0;
    return size(root);
}

int BinaryTree::unique_size()
{
    return unique_size(root);
}

BinaryTree::~BinaryTree()
{
    delete root;
}

void BinaryTree::insert(Node* node, int value)
{
    if(node->value > value){
        if(node->left != nullptr){
            insert(node->left, value);
        }else{
            Node* new_n = new Node;
            new_n->count = 1;
            new_n->value = value;
            node->left = new_n;
            return;
        }
    }else if(node->value < value){
        if(node->right != nullptr){
            insert(node->right, value);
        }else{
            Node* new_n = new Node;
            new_n->count = 1;
            new_n->value = value;
            node->right = new_n;
            return;
        }
    }else{
        node->count++;
    }
}

BinaryTree::Node* BinaryTree::erase(Node* node, int value)
{
    if(node->value == value){
        if(node->count == 1){
            if(node->right == nullptr){
                Node* left = node->left;
                node->left = nullptr;
                delete node;
                return left;
            }
            Node* right = node->right;
            node->right = nullptr;
            delete node;
            return right;
        }else{
            node->count--;
            return node;
        }
    }else if (node->value > value){
        if(node->left != nullptr){
            node->left = erase(node->left, value);
        }
    }else{
        if(node->right != nullptr){
            node->right = erase(node->right, value);
        }
    }
    return node;
}

bool BinaryTree::contains(Node* node, int value)
{
    if(node->value == value){
        return true;
    }else if(node->value > value){
        if(node->left != nullptr){
            return contains(node->left, value);
        }else{
            return false;
        }
    }else{
        if(node->right != nullptr){
            return contains(node->right, value);
        }else{
            return false;
        }
    }
}

void BinaryTree::print(Node* node)
{
    if(node == nullptr) return;
    print(node->left);
    for(int i = 0; i < node->count; i++){
        cout << node->value << " ";
    }
    print(node->right);
}

int BinaryTree::size(Node* node)
{
    if(node == nullptr) return 0;
    return node->count + size(node->left) + size(node->right);
}

int BinaryTree::unique_size(Node* node)
{
    if(node == nullptr) return 0;
    return 1 + unique_size(node->left) + unique_size(node->right);
}