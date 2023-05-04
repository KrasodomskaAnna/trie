#ifndef TRIE_TNODE_H
#define TRIE_TNODE_H

#include <string>
#include <utility>

#define ALPHABET_SIZE 26

class TNode {
public:
    TNode() {
        for(int i = 0; i < ALPHABET_SIZE; i++) {
            this->children[i] = nullptr;
            this->existEdge[i] = false;
        }
    }
    TNode(char key) : TNode() {
        this->key = key;
    }
    char key;
    bool isFinal = false;
    std::string translation;
    TNode* children[ALPHABET_SIZE];
    bool existEdge[ALPHABET_SIZE];
    ~TNode() {
        for(int i = ALPHABET_SIZE-1; i >= 0; i--) {
            delete children[i];
        }
    }
};

#endif //TRIE_TNODE_H
