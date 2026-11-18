#ifndef STACK_H
#define STACK_H

class Stack
{
private:
    struct Node
    {
        int value;
        Node* last = nullptr;
    };

    Node* start = nullptr;

    void insertNumner(int val);

public:
    bool isEmpty();
    void push(int value);
    int pop();
    int size();
    void clear();
    int top();

    void sorted();
    void print();

    Stack(Stack& st);
    Stack(){}
};


#endif // STACK_H
