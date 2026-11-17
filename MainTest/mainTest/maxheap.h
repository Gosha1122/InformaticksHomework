#ifndef MAXHEAP_H
#define MAXHEAP_H

class MaxHeap{
public:
    struct Node{
        long long value;
        Node* right = nullptr;
        Node* left = nullptr;
        Node* parent = nullptr;
        Node* next_added = nullptr;
        Node* last_added = nullptr;
    };
    ~MaxHeap();

    void push(long long value);
    int pop();
    Node* top();
    int count();

private:
    Node* root = nullptr;
    Node* last = nullptr;
    Node* added_node = nullptr;
    int size = 0;

    static void swap(Node* n1, Node* n2);
    void push_back(int value);
    Node* pop_last();

};

#endif // MAXHEAP_H
