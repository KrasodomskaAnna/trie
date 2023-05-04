#include <iostream>
#include "Trie.h"

int main() {
    Trie trie;
    std::string command, word, translation;
    while(std::cin >> command) {
        std::cin >> word;
        if (command[0] == '+') {
            std::cin >> translation;
            trie.add(trie.dictionary, word, translation);
        }
        else if (command[0] == '?')
            std::cout << trie.findRecord(trie.dictionary, word) << std::endl;
        else if (command[0] == '*')
            trie.search(trie.dictionary, word);
    }
    return 0;
}
