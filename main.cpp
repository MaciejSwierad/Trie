#include <iostream>
#include "Trie.h"

int main()
{
    Trie trie;

    char operation;
    std::string word1;
    std::string word2;

    while(std::cin>>operation)
    {
        if(operation == '+')
        {
            std::cin >> word1 >> word2;
            trie.insert(word1, word2);
        }
        else if(operation == '?')
        {
            std::cin >> word1;
            std::cout << trie.search(word1) << std::endl;
        }
        else if(operation == '*')
        {
            std::cin>>word1;
            trie.print(trie.findNodeWithPrefix(word1));
        }
    }
    return 0;
}