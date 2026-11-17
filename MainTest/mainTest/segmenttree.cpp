#include "segmenttree.h"

template <typename T2>
void SegmentTree<T2>::build(std::vector<T2>& v){
    if(v.empty()){
        throw std::exception();
    }
    delete root;
    root = nullptr;
    root = build(0, static_cast<int>(v.size()) - 1, v);
}

template <typename T2>
void SegmentTree<T2>::update(int l, int r, T2 value){
    if(root == nullptr){
        throw std::exception();
    }
    if(l > r){
        throw std::exception();
    }
    if(l < root->l || r > root->r){
        throw std::exception();
    }
    update(root, l, r, value);
}

template <typename T2>
T2 SegmentTree<T2>::calculate(int pos){
    if(root == nullptr){
        throw std::exception();
    }
    if(pos < root->l || pos > root->r){
        throw std::exception();
    }
    return calculate(root, pos);
}

template <typename T2>
typename SegmentTree<T2>::Node* SegmentTree<T2>::build(int l, int r, std::vector<T2>& v){
    if(l == r){
        Node* new_n = new Node;
        new_n->l = l;
        new_n->r = r;
        new_n->value = v[l];
        return new_n;
    }
    Node* new_n = new Node;
    new_n->l = l;
    new_n->r = r;
    new_n->left = build(l, (l + r) / 2, v);
    new_n->right = build((l + r) / 2 + 1, r, v);
    new_n->value = new_n->left->value > new_n->right->value? new_n->left->value : new_n->right->value;
    return new_n;
}

template <typename T2>
void SegmentTree<T2>::update(Node* node, int l, int r, T2 value){
    if(node == nullptr || r < node->l || node->r < l) return;
    if(l <= node->l && node->r <= r){
        node->lazy += value;
        return;
    }
    push_down(node);
    update(node->left, l, r, value);
    update(node->right, l, r, value);
}

template <typename T2>
T2 SegmentTree<T2>::calculate(Node* node, int pos){
    if(node == nullptr){
        throw std::exception();
    }
    if(node->l == node->r && node->l == pos) return node->value + node->lazy;
    if(pos <= (node->l + node->r) / 2){
        push_down(node);
        return calculate(node->left, pos);
    }else{
        push_down(node);
        return calculate(node->right, pos);
    }
}

template <typename T2>
void SegmentTree<T2>::push_down(Node* node){
    if(node->lazy == 0) return;
    if(node->left != nullptr){
        node->left->lazy += node->lazy;
    }
    if(node->right != nullptr){
        node->right->lazy += node->lazy;
    }
    node->lazy = 0;
}