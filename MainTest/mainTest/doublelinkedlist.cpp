#include "doublelinkedlist.h"
#include <iostream>
using namespace std;

DoubleLinkedList::DoubleLinkedList() : header(nullptr), tail(nullptr) {}

DoubleLinkedList::~DoubleLinkedList()
{
    clear();
}

DoubleLinkedList::DoubleLinkedList(DoubleLinkedList&& other) noexcept
    : header(other.header), tail(other.tail)
{
    other.header = nullptr;
    other.tail   = nullptr;
}

DoubleLinkedList& DoubleLinkedList::operator=(DoubleLinkedList&& other) noexcept
{
    if (this != &other)
    {
        clear();
        header = other.header;
        tail   = other.tail;
        other.header = nullptr;
        other.tail   = nullptr;
    }
    return *this;
}

bool DoubleLinkedList::isEmpty()
{
    return header == nullptr;
}

void DoubleLinkedList::addToEnd(string& value)
{
    Node* newNode = new Node({value, nullptr, nullptr});
    if(isEmpty()){
        header = newNode;
        tail = newNode;
        return;
    }
    newNode->prev = tail;
    tail->next = newNode;
    tail = newNode;
}

int DoubleLinkedList::getSize()
{
    int count = 0;
    for(Node* cur = header; cur != nullptr; cur = cur->next){
        count++;
    }
    return count;
}

DoubleLinkedList::Node* DoubleLinkedList::getNodeAt(int i)
{
    if(i < 0) return nullptr;
    Node* cur = header;
    for(int j = 0; cur != nullptr && j < i; ++j){
        cur = cur->next;
    }
    return cur;
}

bool DoubleLinkedList::setValueAt(int i, string& value)
{
    Node* n = getNodeAt(i);
    if(!n) return false;
    n->value = value;
    return true;
}

string DoubleLinkedList::getValueAt(int i)
{
    Node* n = getNodeAt(i);
    return n ? n->value : "";
}

int DoubleLinkedList::find(string& value)
{
    int i = 0;
    for(Node* cur = header; cur != nullptr; cur = cur->next, i++){
        if(cur->value == value) return i;
    }
    return -1;
}

string DoubleLinkedList::maxElement()
{
    if(isEmpty()) return "";
    string maxVal = header->value;
    for(Node* cur = header; cur; cur = cur->next){
        if(maxVal < cur->value) maxVal = cur->value;
    }
    return maxVal;
}

bool DoubleLinkedList::isOrdered()
{
    if(isEmpty()) return false;
    for(Node* cur = header; cur->next != nullptr; cur = cur->next){
        if(cur->value > cur->next->value) return false;
    }
    return true;
}

void DoubleLinkedList::print()
{
    if(isEmpty()){
        cout << "List is empty\n";
        return;
    }
    cout << "List: ";
    for(Node* cur = header; cur != nullptr; cur = cur->next){
        cout << cur->value << " ";
    }
    cout << endl;
}

void DoubleLinkedList::connect(DoubleLinkedList& other)
{
    if(other.isEmpty()) return;

    if(isEmpty()){
        header = other.header;
        tail   = other.tail;
    }else{
        tail->next         = other.header;
        other.header->prev = tail;
        tail               = other.tail;
    }
    other.header = nullptr;
    other.tail   = nullptr;
}

DoubleLinkedList DoubleLinkedList::getTailList()
{
    DoubleLinkedList result;
    if(isEmpty() || header->next == nullptr) return result;
    for(Node* cur = header->next; cur != nullptr; cur = cur->next){
        result.addToEnd(cur->value);
    }
    return result;
}

void DoubleLinkedList::swapAt(int i)
{
    Node* n1 = getNodeAt(i);
    if(!n1 || !n1->next) return;

    Node* n2     = n1->next;
    Node* before = n1->prev;
    Node* after  = n2->next;

    if(before){
        before->next = n2;
    }else{
        header = n2;
    }
    n2->prev = before;

    n2->next = n1;
    n1->prev = n2;

    n1->next = after;
    if(after){
        after->prev = n1;
    }else{
        tail = n1;
    }
}

void DoubleLinkedList::sort()
{
    if(isEmpty()) return;
    int n = getSize();
    for(int i = 0; i < n - 1; ++i){
        for (int j = 0; j < n - 1 - i; ++j)
        {
            Node* n1 = getNodeAt(j);
            if (!n1 || !n1->next) break;
            if (n1->value < n1->next->value) swapAt(j);
        }
    }
}

string DoubleLinkedList::concatenate()
{
    string result;
    for(Node* cur = header; cur != nullptr; cur = cur->next){
        result += cur->value;
    }
    return result;
}

void DoubleLinkedList::clear()
{
    Node* cur = header;
    while(cur){
        Node* next = cur->next;
        delete cur;
        cur = next;
    }
    header = nullptr;
    tail   = nullptr;
}