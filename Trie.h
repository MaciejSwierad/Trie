#ifndef TRIE_TRIE_H
#define TRIE_TRIE_H

#include <iostream>
#include <string>
#include "Node.cpp"

class Trie {
public:
    Trie();
    void insert(std::string, std::string);
    Node* getNode();
    std::string search(std::string key);
    Node* findNodeWithPrefix(std::string);
    void print(Node*);

    Node* root;
};


#endif //TRIE_TRIE_H