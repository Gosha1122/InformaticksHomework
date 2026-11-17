#include "stack.h"

bool Stack::IsEmpty()
{
    if (start == nullptr) return true;
    return false;
}

void Stack::Push(double value)
{
    Node* newNode = new Node{ value, start };
    start = newNode;
}

double Stack::Pop()
{
    if(!IsEmpty()){
        Node* firstNode = start;
        start = firstNode->last;
        double value = firstNode->value;
        delete firstNode;
        return value;
    }
    return -1.0;
}

int Stack::Size()
{
    if(!IsEmpty()){
        Node* next = start;
        int size = 0;
        while (next != nullptr)
        {
            size++;
            next = next->last;
        }
        return size;
    }
    return 0;
}

void Stack::Clear()
{
    for(int i = Size(); i > 0; i--){
        Pop();
    }
}

double Stack::Front()
{
    double v = Pop();
    Push(v);
    return v;
}