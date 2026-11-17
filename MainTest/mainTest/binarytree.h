#ifndef BINARYTREE_H
#define BINARYTREE_H

class BinaryTree
{
private:
    struct Node
    {
        int value;
        Node* left = nullptr;
        Node* right = nullptr;
        int count;
        ~Node();
    };

    Node* root = nullptr;

    void insert(Node* node, int value);
    Node* erase(Node* node, int value);
    bool contains(Node* node, int value);
    void print(Node* node);
    int size(Node* node);
    int unique_size(Node* node);

public:
    bool isEmpty();
    void insert(int value);
    void erase(int value);
    bool contains(int value);
    void print();
    int size();
    int unique_size();
    ~BinaryTree();
};


#endif // BINARYTREE_H
