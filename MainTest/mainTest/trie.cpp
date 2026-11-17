#include "trie.h"

Trie::Trie() {}

void Trie::insert(std::string &str)
{
    Node* node = root;
    int n = str.size();
    for(int i = 0; i < n; i++){
        node->count++;
        if((node->symbols)[str[i]] != nullptr){
            node = (node->symbols)[str[i]];
        }else{
            node->symbols[str[i]] = new Node();
            node = node->symbols[str[i]];
        }
    }

    node->count_words++;
    node->is_end = true;
    node->count = 1;
}

bool Trie::starts_with(std::string &prefix)
{
    if(root == nullptr){
        std::exception();
        return false;
    }
    Node* node = root;
    int n = prefix.size();
    for(int i = 0; i < n; i++){
        if(node->symbols[prefix[i]] == nullptr){
            return false;
        }
        node = node->symbols[prefix[i]];
    }
    return true;
}

bool Trie::contains(std::string &word)
{
    if(root == nullptr){
        std::exception();
        return false;
    }
    Node* node = root;
    int n = word.size();
    for(int i = 0; i < n; i++){
        if(node->symbols[word[i]] == nullptr){
            return false;
        }else{
            node = node->symbols[word[i]];
        }
    }
    return node->is_end;
}

void Trie::insert(std::string &&str)
{
    std::string t = str;
    insert(t);
}

bool Trie::contains(std::string &&word)
{
    std::string t = word;
    return contains(t);
}

bool Trie::starts_with(std::string &&prefix)
{
    std::string t = prefix;
    return starts_with(t);
}

void Trie::sorted(std::vector<std::string> &words)
{
    if(root == nullptr){
        std::exception();
        return;
    }
    sorted(root, words, "");
}

void Trie::sorted(Node *node, std::vector<std::string> &words, std::string str)
{
    if(node == nullptr) return;
    if(node->is_end){
        for(int i = 0; i < node->count_words; i++){
            words.push_back(str);
        }
    }
    for(auto b = node->symbols.begin(); b != node->symbols.end(); b++){
        sorted(b->second, words, str + b->first);
    }
}


Trie::Node::Node(bool is_end, std::map<char, Node *> symbols, int count):is_end(is_end), symbols(symbols), count(count){

}

