#include <iostream>

using namespace std;

struct Node{
    double value;
    Node* last = nullptr;
};

struct Stack{
    Node* start = nullptr;
};



bool IsEmpty(Stack* queue){
    if(queue->start == nullptr) return true;
    return false;
}

void Push(Stack* queue, double value){
    Node* newNode = new Node({value, queue->start});
    queue->start = newNode;
}

double Pop(Stack* queue){
    if(!IsEmpty(queue)){
        Node* firstNode = queue->start;
        queue->start = firstNode->last;
        double value = firstNode->value;
        delete firstNode;
        return value;
    }
    return -1.0;
}

int Size(Stack* queue){
    if(!IsEmpty(queue)){
        Node* next = queue->start;
        int size = 0;
        while(next != nullptr){
            size++;
            next = next->last;
        }
        return size;
    }
    return 0;
}

void Clear(Stack* queue){
    for(int i = Size(queue); i > 0; i--){
        Pop(queue);
    }
}

double Front(Stack* queue){
    double v = Pop(queue);
    Push(queue, v);
    return v;
}

int main()
{
    Stack* queue = new Stack;
    cout << "Stack is empty: " << (IsEmpty(queue)? "True": "False") << endl;
    Push(queue, 5.33);
    cout << "Stack is empty: " << (IsEmpty(queue)? "True": "False") << endl;

    Push(queue, 15.33);
    Push(queue, 2.39);

    cout << "First Stack elment: " << Pop(queue) << endl;
    cout << "First Stack elment: " << Pop(queue) << endl;

    cout << "Stack size: " << Size(queue) << endl;
    Push(queue, 5.33);
    cout << "Stack size: " << Size(queue) << endl;

    cout << "Stack front: " << Front(queue) << endl;
    Pop(queue);
    cout << "Stack front: " << Front(queue) << endl;

    cout << "Stack size: " << Size(queue) << endl;
    Clear(queue);
    cout << "Stack size: " << Size(queue) << endl;
    delete queue;
}