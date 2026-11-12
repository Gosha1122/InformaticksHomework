#include <iostream>
#include <vector>
#include <map>
#include <algorithm>

using namespace std;

struct Node{
    bool is_end = false;
    map<char, Node*> symbols;
    int count = 0;
    int count_words = 0;

    Node(){}
    Node(bool is_end, map<char, Node*> symbols, int count):is_end(is_end), symbols(symbols), count(count){}
    ~Node(){}
};

class Trie{
public:
    Trie(){
        root = new Node();
    }
    ~Trie(){
        delete root;
    }

    void insert(string& str){
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

    bool starts_with(string& prefix){
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

    bool contains(string& word){
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

    void insert(string&& str){
        string t = str;
        insert(t);
    }

    bool contains(string&& word){
        string t = word;
        return contains(t);
    }

    bool starts_with(string&& prefix){
        string t = prefix;
        return starts_with(t);
    }

    void sorted(vector<string>& words){
        sorted(root, words, "");
    }

private:
    Node* root = nullptr;

    void sorted(Node* node, vector<string>& words, string str){
        if(node->is_end){
            for(int i = 0; i < node->count_words; i++){
                words.push_back(str);
            }
        }
        for(auto b = node->symbols.begin(); b != node->symbols.end(); b++){
            sorted(b->second, words, str + b->first);
        }
    }
};

int split(string& str, vector<string>& word, vector<int>& count_point){
    str += '.';
    int n = str.size();
    int index = 0;
    bool is_word = false;
    int count = 0;
    int word_counts = 0;
    for(int i = 0; i < n; i++){
        if(is_word){
            if(str[i] == '.'){
                word.push_back(str.substr(index, i - index));
                is_word = false;
                index = i;
                word_counts++;
            }
        }else{
            if(str[i] != '.'){
                count_point.push_back(i - index);
                is_word = true;
                index = i;
                count++;
            }
        }
    }
    //count_point[count - 1]--;
    if(str[n - 2] == '.'){
        count_point.push_back(n - index - 1);
    }
    return word_counts;
}

int main()
{
    // string str;
    // getline(cin, str);
    // vector<int> count_point;
    // vector<string> word;
    // int n = split(str, word, count_point);
    // // for(int i = 0; i < n; i++){
    // //     cout << word[i] << endl;
    // // }
    // // for(int i = 0; i < count_point.size(); i++){
    // //     cout << count_point[i] << endl;
    // // }

    // // Trie trie;
    // // for(int i = 0; i < n; i++){
    // //     trie.insert(word[i]);
    // // }
    // // vector<string> words;
    // // trie.sorted(words);

    // sort(word.begin(), word.end());

    // for(int i = 0; i < n; i++){
    //     for(int j = 0; j < count_point[i]; j++){
    //         cout << '.';
    //     }
    //     cout << word[i];
    // }
    // if(str[str.size() - 2] == '.'){
    //     for(int j = 0; j < count_point[n]; j++){
    //         cout << '.';
    //     }
    // }

}