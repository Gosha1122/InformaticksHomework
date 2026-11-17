#ifndef DOUBLELINKEDLIST_H
#define DOUBLELINKEDLIST_H

#include <string>

class DoubleLinkedList{
public:
    DoubleLinkedList();

    ~DoubleLinkedList();

    DoubleLinkedList(DoubleLinkedList&) = delete;
    DoubleLinkedList& operator=(DoubleLinkedList&) = delete;
    DoubleLinkedList(DoubleLinkedList&& other) noexcept;
    DoubleLinkedList& operator=(DoubleLinkedList&& other) noexcept;

    bool isEmpty();

    void addToEnd(std::string& value);

    int getSize();

    bool setValueAt(int i, std::string& value);
    std::string getValueAt(int i) ;

    int find(std::string& value);
    std::string maxElement();
    bool isOrdered();

    void print();

    void connect(DoubleLinkedList& other);
    DoubleLinkedList  getTailList();

    void swapAt(int i);
    void sort();

    std::string concatenate();

    void clear();

    struct Node{
        std::string value;
        Node* next = nullptr;
        Node* prev = nullptr;
    };

private:

    Node* header;
    Node* tail;

    Node* getNodeAt(int i);

};

#endif // DOUBLELINKEDLIST_H
