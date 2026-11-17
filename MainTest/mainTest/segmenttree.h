#ifndef SEGMENTTREE_H
#define SEGMENTTREE_H

#include <vector>

template <typename T2>
class SegmentTree{
private:
    struct Node{
        T2 value;
        T2 lazy = T2();
        Node* left = nullptr;
        Node* right = nullptr;
        int l = 0;
        int r = 0;

        ~Node(){
            delete left;
            delete right;
        }
    };

    Node* root = nullptr;

    Node* build(int l, int r, std::vector<T2>& v);
    void update(Node* node, int l, int r, T2 value);
    T2 calculate(Node* node, int pos);
    void push_down(Node* node);

public:
    SegmentTree() = default;
    ~SegmentTree(){ delete root; }

    SegmentTree(const SegmentTree&) = delete;
    SegmentTree& operator=(const SegmentTree&) = delete;

    void build(std::vector<T2>& v);
    void update(int l, int r, T2 value);
    T2 calculate(int pos);
};


#endif // SEGMENTTREE_H
