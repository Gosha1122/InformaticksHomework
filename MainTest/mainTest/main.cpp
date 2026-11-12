#include <iostream>

using namespace std;

struct Node{
    long long value;
    Node* right = nullptr;
    Node* left = nullptr;
    Node* parent = nullptr;
    Node* next_added = nullptr;
    Node* last_added = nullptr;
};

void swap(Node* n1, Node* n2){
    long long t = n2->value;
    n2->value = n1->value;
    n1->value = t;

}

class HeapMax{
public:
    void push(long long value){
        push_back(value);
        Node* n = last;
        while(n->parent != nullptr && n->parent->value < n->value){
            swap(n->parent, n);
            n = n->parent;
        }
    }

    int pop() {
        if (root == nullptr) {
            return -1;
        }

        if (root == last) {
            long long res = root->value;
            delete root;
            root = nullptr;
            last = nullptr;
            added_node = nullptr;
            size = 0;
            return res;
        }

        swap(root, last);

        Node* n = pop_last();
        long long res = n->value;
        delete n;

        Node* t = root;
        while (true) {
            Node* largest = t;

            if (t->left != nullptr && t->left->value > largest->value) {
                largest = t->left;
            }
            if (t->right != nullptr && t->right->value > largest->value) {
                largest = t->right;
            }

            if (largest == t) break;

            swap(t, largest);
            t = largest;
        }

        return res;
    }

    Node* top(){
        return root;
    }

    int count(){
        return size;
    }

private:
    Node* root = nullptr;
    Node* last = nullptr;
    Node* added_node = nullptr;
    int size = 0;

    void push_back(int value){
        if(root == nullptr){
            root = new Node;
            root->value = value;
            last = root;
            added_node = root;
            size = 1;
        }else{
            size++;
            Node* n = new Node;
            n->value = value;
            last->next_added = n;
            n->last_added = last;
            last = n;
            if(added_node->left == nullptr) added_node->left = n;
            else added_node->right = n;
            n->parent = added_node;
            if (added_node->left != nullptr && added_node->right != nullptr){
                added_node = added_node->next_added;
            }
        }
    }

    Node* pop_last() {
        if (root == nullptr) return nullptr;

        Node* res = last;

        if (res == root) {
            root = nullptr;
            last = nullptr;
            added_node = nullptr;
            size = 0;
            return res;
        }

        Node* p = res->parent;
        if (p != nullptr) {
            if (p->left == res) p->left = nullptr;
            else if (p->right == res) p->right = nullptr;
        }

        Node* new_last = res->last_added;
        last = new_last;
        if (last != nullptr) {
            last->next_added = nullptr;
        }

        added_node = p;

        size--;
        return res;
    }


};

int main() {
    // HeapMax heap;

    // int n; cin >> n;
    // for(int i = 0; i < n; i++){
    //     int c; cin >> c;
    //     if(c == 0){
    //         int value; cin >> value;
    //         heap.push(value);
    //     }else{
    //         cout << heap.pop() << endl;
    //     }
    // }

}