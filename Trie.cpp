#include "Trie.h"

Trie::Trie()
{
    root = getNode();
}

void Trie::insert(std::string word, std::string translation)
{
    Node* Crawler = root;

    for (int i = 0; i < word.length(); ++i)
    {
        int index = word[i] - 'a';

        if(!Crawler->children[index])
        {
            Crawler->children[index] = getNode();

        }

        Crawler = Crawler->children[index];

    }

    Crawler->isEndOfWord = true;
    Crawler->translation = translation;

}

Node *Trie::getNode()
{
    Node* node = new Node;

    node->isEndOfWord = false;

    for (int i = 0; i < ALPHABET_SIZE; ++i)
    {
        node->children[i] = nullptr;

    }

    return node;
}

std::string Trie::search(std::string key)
{
    Node* Crawler = root;

    for (int i = 0; i < key.length(); ++i)
    {
        int index = key[i] - 'a';

        if(!Crawler->children[index])
            return "-";

        Crawler = Crawler->children[index];

    }

    if(Crawler != nullptr && Crawler->isEndOfWord)
    {
        return Crawler->translation;

    }
    else
    {
        return "-";

    }

    //unreachable
    return "-";
}

Node* Trie::findNodeWithPrefix(std::string prefix)
{
    Node* Crawler = root;

    for (int i = 0; i < prefix.length(); ++i)
    {
        int index = prefix[i] - 'a';

        if(!Crawler->children[index])
        {
            std::cout<<"-"<<std::endl;
            return nullptr;

        }

        Crawler = Crawler->children[index];

    }

    return Crawler;
}

void Trie::print(Node* node)
{
    if(node != nullptr)
    {
        if (node->isEndOfWord)
            std::cout << node->translation << std::endl;

        for (int i = 0; i < ALPHABET_SIZE; ++i)
        {
            if (node->children[i])
            {
                print(node->children[i]);

            }

        }

    }
}