#ifndef TRIE_TRIE_H
#define TRIE_TRIE_H

#include "TNode.h"

class Trie {
public:
    TNode* dictionary;
    Trie() {
        dictionary = new TNode[ALPHABET_SIZE];
    }
    TNode* add(TNode* root, std::string word, std::string translation) {
        if(word.empty()) {
            root->isFinal = true;
            root->translation = translation;
            return root;
        }
        int id = word[0]-'a';
        if(!root->existEdge[id])
            root->children[id] = new TNode(word[0]);
        root->children[id] = add(root->children[id], word.substr(1, word.length()), translation);
        root->existEdge[id] = true;
        return root;
    }
    std::string findRecord(TNode* root, std::string word) {
        if(word.empty()) {
            if(!root->isFinal) return "-";
            return root->translation;
        }
        int id = word[0]-'a';
        if(!root->existEdge[id]) return "-";
        return findRecord(root->children[id], word.substr(1, word.length()));
    }
    void search(TNode* root, std::string word) {
        if(word.empty()) {
            if(root->isFinal) std::cout << root->translation << std::endl;

            for(int i = 0; i < ALPHABET_SIZE; i++) {
                if(root->existEdge[i])
                    search(root->children[i], word);
            }

            return;
        }
        int id = word[0]-'a';
        if(!root->existEdge[id]) {
            std::cout << "-" << std::endl;
            return;
        }
        search(root->children[id], word.substr(1, word.length()));
    }
    ~Trie() {
        delete[] dictionary;
    }
};

#endif //TRIE_TRIE_H
