#include <iostream>
#include <string>

#define ALPHABET_SIZE 26

struct Node
{
    struct Node* children[ALPHABET_SIZE];
    bool isEndOfWord;
    std::string translation;
};