#include <iostream>
#include <vector>

using namespace std;

template <typename T1>
struct Node{
    T1 value;
    T1 lazy;
    Node* left = nullptr;
    Node* right = nullptr;
    int l;
    int r;
};

template <typename T2>
class SegmentTree{
public:
    void build(vector<T2>& v){
        root = build(0, v.size() - 1, v);
    }

    void update(int l, int r, T2 value){
        update(root, l, r, value);
    }

    T2 calculate(int pos){
        return calculate(root, pos);
    }
private:
    Node<T2>* root = nullptr;
    Node<T2>* build(int l, int r, vector<T2>& v){
        if(l == r){
            Node<T2>* new_n = new Node<T2>;
            new_n->l = l;
            new_n->r = r;
            new_n->value = v[l];
            return new_n;
        }
        Node<T2>* new_n = new Node<T2>;
        new_n->l = l;
        new_n->r = r;
        new_n->left = build(l, (l + r) / 2, v);
        new_n->right = build((l + r) / 2 + 1, r, v);
        new_n->value = new_n->left->value > new_n->right->value? new_n->left->value : new_n->right->value;
        return new_n;
    }

    void update(Node<T2>* node, int l, int r, T2 value){
        if(node == nullptr || r < node->l || node->r < l) return;
        if(l <= node->l && node->r <= r){
            node->lazy += value;
            return;
        }
        push_down(node);
        update(node->left, l, r, value);
        update(node->right, l, r, value);
    }

    T2 calculate(Node<T2>* node, int pos){
        if(node->l == node->r && node->l == pos) return node->value + node->lazy;
        if(pos <= (node->l + node->r) / 2){
            push_down(node);
            return calculate(node->left, pos);
        }else{
            push_down(node);
            return calculate(node->right, pos);
        }
    }

    void push_down(Node<T2>* node){
        if(node->lazy == 0) return;
        if(node->left != nullptr){
            node->left->lazy += node->lazy;
        }
        if(node->right != nullptr){
            node->right->lazy += node->lazy;
        }
        node->lazy = 0;
    }
};


int main()
{
    // int n; cin >> n;
    // SegmentTree<long long> s;
    // vector<long long> v(n);
    // for(int i = 0; i < n; i++){
    //     long long t; cin >> t;
    //     v[i] = t;
    // }
    // s.build(v);

    // int m; cin >> m;
    // for(int i = 0; i < m; i++){
    //     char ch; cin >> ch;
    //     if(ch == 'g'){
    //         long long t; cin >> t;
    //         cout << s.calculate(t - 1) << endl;
    //     }else{
    //         long long l, r, delta; cin >> l >> r >> delta;
    //         s.update(l - 1, r - 1, delta);
    //     }
    // }
}