#include "stack.h"
#include <iostream>

void Stack::insertNumner(int val)
{
    if(this->isEmpty()){
        this->push(val);
        return;
    }
    if(this->top() > val){
        int t = this->pop();
        insertNumner(val);
        this->push(t);
    }else{
        this->push(val);
    }
}

bool Stack::isEmpty()
{
    if (start == nullptr) return true;
    return false;
}

void Stack::push(int value)
{
    Node* newNode = new Node{ value, start };
    start = newNode;
}

int Stack::pop()
{
    if(!isEmpty()){
        Node* firstNode = start;
        start = firstNode->last;
        int value = firstNode->value;
        delete firstNode;
        return value;
    }
    return -1.0;
}

int Stack::size()
{
    if(!isEmpty()){
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

void Stack::clear()
{
    for(int i = size(); i > 0; i--){
        pop();
    }
}

int Stack::top()
{
    int v = pop();
    push(v);
    return v;
}

void Stack::sorted()
{
    Stack stack_t;
    for(int _ = 0; !this->isEmpty(); ){
        stack_t.insertNumner(this->pop());
    }
    this->start = stack_t.start;
}

void Stack::print()
{
    if(this->isEmpty()) return;
    int t = this->pop();
    std::cout << t << " ";
    print();
    this->push(t);
}

Stack::Stack(Stack &st)
{
    start = st.start;
}

