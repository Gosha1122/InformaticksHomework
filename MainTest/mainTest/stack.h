#ifndef STACK_H
#define STACK_H

class Stack
{
private:
    struct Node
    {
        double value;
        Node* last = nullptr;
    };

    Node* start = nullptr;

public:
    bool IsEmpty();
    void Push(double value);
    double Pop();
    int Size();
    void Clear();
    double Front();
};


#endif // STACK_H
