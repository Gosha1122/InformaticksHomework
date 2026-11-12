#include <iostream>
#include <string>
using namespace std;

// структура узла списка
struct Node
{
    string value; // значение узла списка
    Node* next; // указатель на следующий узел за текущим
    Node* prev;
};

// структура списка
struct List
{
    Node* header; // указатель на головной элемент списка
    Node* tail;
};

Node* createNode(string value) // Функция нужна, чтобы проще создавать узел со значением value и в дальнейшем
{
    Node* newNode = new Node();
    newNode->value = value;
    newNode->next = nullptr; // следующий элемент за создаваемым узлом остаётся nullptr, поскольку не знаем, каким он будет
    newNode->prev = nullptr;
    return newNode;
}

// Функция создания пустого списка
List* createList()
{
    List* list = new List();
    list->header = nullptr; // изначально создаётся пустой список и его головной элемент(header) = nullptr
    list->tail = nullptr;
    return list;
}

// Функция проверки списка на пустоту
bool isEmpty(List* list)
{
    if (list->header == nullptr) // если список пуст, то его головной элемент = nullptr
    {
        return true;
    }
    return false;
}

// Функция добавления значения в конец списка
void addToEnd(List* list, string value)
{
    Node* newNode = createNode(value); // это последний узел, поэтому его next остаётся nullptr
    if (isEmpty(list))
    {
        list->header = newNode;
        list->tail = newNode;
        return;
    }
    Node* lastNode = list->header; // если список не пуст, то у него есть header. lastNode - временная переменная для поиска последнего элемента в списке
    while (lastNode->next != nullptr) // если lastNode -> next == nullptr, то это последний элемент в списке
    {
        lastNode = lastNode->next;
    }
    newNode->prev = lastNode;
    lastNode->next = newNode; // меняем указатель следующего за lastNode узла на newNode
    list->tail = newNode;
}

Node* getLastListElement(List* list)
{
    if (isEmpty(list))
    {
        return nullptr;
    }
    else
    {
        Node* lastNode = list->header; // если список не пуст, то у него есть header. lastNode - временная переменная для поиска последнего элемента в списке
        while (lastNode->next != nullptr) // если lastNode -> next == nullptr, то это последний элемент в списке
        {
            lastNode = lastNode->next;
        }
        return lastNode;
    }
}

int getLenList(List* list)
{
    if (isEmpty(list))
    {
        return 0;
    }
    else
    {
        int countElement = 1;
        Node* lastNode = list->header; // если список не пуст, то у него есть header. lastNode - временная переменная для поиска последнего элемента в списке
        while (lastNode->next != nullptr) // если lastNode -> next == nullptr, то это последний элемент в списке
        {
            lastNode = lastNode->next;
            countElement++;
        }
        return countElement;
    }
}

bool setListValueIndexElement(List* list, int i, string value)
{
    if (i >= 0 && i < getLenList(list))
    {
        Node* index_node = list->header;
        for (int j = 0; j < i; j++)
        {
            index_node = index_node->next;
        }
        index_node->value = value;
        return true;
    }
    else
    {
        return false;
    }
}

Node* getListElemenIndex(List* list, int i)
{
    if (i >= 0 && i < getLenList(list))
    {
        Node* index_node = list->header;
        for (int j = 0; j < i; j++)
        {
            index_node = index_node->next;
        }
        return index_node;
    }
    return nullptr;
}

string getListValueElementIndex(List* list, int i)
{
    if (i >= 0 && i < getLenList(list))
    {
        Node* index_node = list->header;
        for (int j = 0; j < i; j++)
        {
            index_node = index_node->next;
        }
        return index_node->value;
    }
    return "";
}

int findListvalueElement(List* list, string value)
{
    int n = getLenList(list);
    Node* n_node = list->header;
    for (int i = 0; i < n; i++)
    {
        if (n_node->value == value)
        {
            return i;
        }
        n_node = n_node->next;
    }
    return -1;
}

string maxElementList(List* list)
{
    if (isEmpty(list))
    {
        return "";
    }
    else
    {
        Node* next = list->header;
        string maxVal = list->header->value;
        while (next != nullptr)
        {
            if (maxVal < next->value)
            {
                maxVal = next->value;
            }
            next = next->next;
        }
        return maxVal;
    }
}

bool isOrderlyList(List* list)
{
    if (isEmpty(list))
    {
        return false;
    }
    else
    {
        Node* next = list->header;
        while (next->next != nullptr)
        {
            if (next->value > next->next->value)
            {
                return false;
            }
            next = next->next;
        }
        return true;
    }
}

void printList(List* list)
{
    if (isEmpty(list))
    {
        cout << "List is empty\n";
        return;
    }
    else
    {
        cout << "List: ";
        Node* next = list->header;
        while (next != nullptr)
        {
            cout << next->value << " ";
            next = next->next;
        }
        cout << endl;
    }
}

void connectingLists(List* list_1, List* list_2)
{
    if (isEmpty(list_2))
    {
        return;
    }
    else if (isEmpty(list_1))
    {
        list_1->header = list_2->header;
        list_1->tail = list_2->tail;
        return;
    }
    else
    {
        list_1->tail->next = list_2->header;
        list_2->header->prev = list_1->tail;
        list_1->tail = list_2->tail;
        return;
    }
}

List* getTailList(List* list)
{
    List* tail = createList();

    if (isEmpty(list) || list->header->next == nullptr)
    {
        return tail;
    }

    Node* next = list->header->next;
    while (next != nullptr)
    {
        addToEnd(tail, next->value);
        next = next->next;
    }

    return tail;
}

void swapElementList(List* list, int i)
{
    Node* n1 = getListElemenIndex(list, i);

    if (n1 == nullptr || n1->next == nullptr)
    {
        return;
    }

    Node* n2 = n1->next;
    Node* before = n1->prev;
    Node* after = n2->next;

    if (before != nullptr)
    {
        before->next = n2;
    }
    else
    {
        list->header = n2;
    }
    n2->prev = before;

    n2->next = n1;
    n1->prev = n2;

    n1->next = after;
    if (after != nullptr)
    {
        after->prev = n1;
    }
    else
    {
        list->tail = n1;
    }
}

void sortList(List* list)
{
    if (isEmpty(list))
    {
        return;
    }

    int n = getLenList(list);
    for (int i = 0; i < n - 1; i++)
    {
        for (int j = 0; j < n - 1 - i; j++)
        {
            Node* n1 = getListElemenIndex(list, j);

            if (n1 == nullptr || n1->next == nullptr)
            {
                break;
            }

            Node* n2 = n1->next;
            if (n1->value < n2->value)
            {
                swapElementList(list, j);
            }
        }
    }
}

string connectListElement(List* list)
{
    string otv = "";
    if (isEmpty(list))
    {
        return otv;
    }
    else
    {
        Node* next = list->header;
        while (next != nullptr)
        {
            otv += next->value;
            next = next->next;
        }
        return otv;
    }
}

void clearList(List* list)
{
    Node* next = list->header;

    while (next != nullptr)
    {
        Node* nextNode = next->next;
        delete next;
        next = nextNode;
    }

    list->header = nullptr;
    list->tail = nullptr;
}

// Проверки писать не обязательно, но настоятельно рекомендуется, чтобы проверить то, что написали!!!
int main()
{
    List* list = createList(); // создание пустого списка
    cout << "is Empty:" << (isEmpty(list) ? "No" : "Yes") << endl; // проверка работы функции isEmpty
    addToEnd(list, "533"); // добавление элемента в конец списка
    cout << "is Empty:" << (isEmpty(list) ? "No" : "Yes") << endl; // проверка работы функции isEmpty

    addToEnd(list, "53"); // добавление элемента в конец списка
    cout << "Last element: " << getLastListElement(list)->value << endl; // Проверка работы функции getLastListElement
    addToEnd(list, "5333"); // добавление элемента в конец списка
    cout << "Last element: " << getLastListElement(list)->value << endl; // Проверка работы функции getLastListElement

    cout << "Count list element: " << getLenList(list) << endl; // Проверка работы функции getLenList
    addToEnd(list, "5");
    cout << "Count list element: " << getLenList(list) << endl; // Проверка работы функции getLenList

    cout << "Header list element: " << list->header->next->value << endl; // Проверка работы функции setListValueIndexElement
    setListValueIndexElement(list, 1, "-1");
    cout << "Header list element: " << list->header->next->value << endl; // Проверка работы функции setListValueIndexElement

    cout << "List element at index 3: " << getListElemenIndex(list, 3)->value << endl; // Проверка работы функции getListElemenIndex
    setListValueIndexElement(list, 3, "-1");
    cout << "Count list element: " << getListValueElementIndex(list, 3) << endl; // Проверка работы функции getListValueElementIndex

    cout << "Index list element value is 5333: " << findListvalueElement(list, "5333") << endl; // Проверка работы функции findListvalueElement
    setListValueIndexElement(list, 1, "5333");
    cout << "Index list element value is 5333: " << findListvalueElement(list, "5333") << endl; // Проверка работы функции findListvalueElement

    cout << "Max element list: " << maxElementList(list) << endl;

    printList(list);
    cout << "Is orderly list: " << (isOrderlyList(list) ? "Yes" : "No") << endl;
    setListValueIndexElement(list, 3, "53333");
    printList(list);
    cout << "Is orderly list: " << (isOrderlyList(list) ? "Yes" : "No") << endl;

    List* list_2 = createList();
    addToEnd(list_2, "533333");
    addToEnd(list_2, "53333");
    printList(list_2);
    connectingLists(list, list_2);
    printList(list);

    cout << "Tail ";
    printList(getTailList(list));

    cout << "Sort ";
    sortList(list);
    printList(list);

    cout << "All element list: " << connectListElement(list) << endl;

    clearList(list);
    printList(list);
    delete list;

    return 0;
}