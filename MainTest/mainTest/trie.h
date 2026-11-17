#ifndef TRIE_H
#define TRIE_H

#include <vector>
#include <string>
#include <map>

class Trie
{
public:
    Trie();
    ~Trie();

    void insert(std::string& str);

    bool starts_with(std::string& prefix);

    bool contains(std::string& word);

    void insert(std::string&& str);

    bool contains(std::string&& word);

    bool starts_with(std::string&& prefix);

    void sorted(std::vector<std::string>& words);

    struct Node{
        bool is_end = false;
        std::map<char, Node*> symbols;
        int count = 0;
        int count_words = 0;
        Node();
        ~Node();
        Node(bool is_end, std::map<char, Node*> symbols, int count);
    };

private:
    Node* root = nullptr;

    void sorted(Node* node, std::vector<std::string>& words, std::string str);
};

#endif // TRIE_H
