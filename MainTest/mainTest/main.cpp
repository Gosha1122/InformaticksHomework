#include <iostream>

using namespace std;

struct Node{
    int value;
    Node* left = nullptr;
    Node* right = nullptr;
    int count;
    ~Node(){
        if(left != nullptr){
            delete left;
        }
        if(right != nullptr){
            delete right;
        }
    }
};

class BinaryTree{
public:
    bool isEmpty(){
        return (root == nullptr);
    }

    void insert(int value){
        if(root == nullptr){
            root = new Node;
            root->count = 1;
            root->value = value;
            return;
        }
        insert(root, value);
    }

    void erase(int value){
        if(isEmpty()) return;
        root = erase(root, value);
    }

    bool contains(int value){
        if(isEmpty()) return false;
        return contains(root, value);
    }

    void print(){
        print(root);
    }

    int size(){
        if(isEmpty()) return 0;
        return size(root);
    }

    int unique_size(){
        return unique_size(root);
    }

    ~BinaryTree(){
        delete root;
    }
private:
    Node* root = nullptr;

    void insert(Node* node, int value){
        if(node->value > value){
            if(node->left != nullptr){
                insert(node->left, value);
            }else{
                Node* new_n = new Node;
                new_n->count = 1;
                new_n->value = value;
                node->left = new_n;
                return;
            }
        }else if(node->value < value){
            if(node->right != nullptr){
                insert(node->right, value);
            }else{
                Node* new_n = new Node;
                new_n->count = 1;
                new_n->value = value;
                node->right = new_n;
                return;
            }
        }else{
            node->count++;
        }
    }

    Node* erase(Node* node, int value){
        if(node->value == value){
            if(node->count == 1){
                if(node->right == nullptr){
                    return node->left;
                }
                Node* n = node->right;
                while(n->left != nullptr){
                    n = n->left;
                }
                n = node->left;
                Node* n_1 = node->right;
                return n_1;
            }else{
                node->count--;
                return node;
            }
        }else if(node->value > value){
            if(node->left != nullptr){
                node->left = erase(node->left, value);
            }
        }else{
            if(node->right != nullptr){
                node->right = erase(node->right, value);
            }
        }
        return node;
    }

    bool contains(Node* node, int value){
        if(node->value == value){
            return true;
        }else if(node->value > value){
            if(node->left != nullptr){
                return contains(node->left, value);
            }else{
                return false;
            }
        }else{
            if(node->right != nullptr){
                return contains(node->right, value);
            }else{
                return false;
            }
        }
    }

    void print(Node* node){
        if(node == nullptr) return;
        print(node->left);
        for(int i = 0; i < node->count; i++){
            cout << node->value << " ";
        }
        print(node->right);
    }

    int size(Node* node){
        if(node == nullptr) return 0;
        return node->count + size(node->left) + size(node->right);
    }

    int unique_size(Node* node){
        if(node == nullptr) return 0;
        return 1 + unique_size(node->left) + unique_size(node->right);
    }
};

int main()
{
    BinaryTree tree;
    tree.insert(1);
    tree.insert(1);
    tree.insert(2);
    tree.insert(4);
    tree.insert(3);
    tree.insert(2);
    tree.print();
    cout << endl;
    tree.erase(1);
    tree.print();
    cout << endl;
    tree.erase(1);
    tree.print();
    cout << endl;
}
