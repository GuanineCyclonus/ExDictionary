#include <cstring>
#include <iostream>
#include <string>
#include <string_view>
#include "Trie.h"

Trie::Trie() {
    memset(nextLetter, 0, sizeof(nextLetter));
    nodeCount = 0;
}
Trie::~Trie() {}

int Trie::insert(std::string_view str) {
    int CurrentNode = 0;
    for (auto letter : str) {
        if (!nextLetter[CurrentNode][letter]) {
            nextLetter[CurrentNode][letter] = ++nodeCount;
        }
        CurrentNode = nextLetter[CurrentNode][letter];
    }
    if (wordEnd[CurrentNode]) {
        return 0;
    } else {
        wordEnd[CurrentNode] = true;
        return 1;
    }
}

int Trie::erase(std::string_view str) {
    int CurrentNode = 0;
    for (auto letter : str) {
        if (!nextLetter[CurrentNode][letter]) {
            return 0;
        }
        CurrentNode = nextLetter[CurrentNode][letter];
    }
    if (!wordEnd[CurrentNode]) {
        return 0;
    } else {
        wordEnd[CurrentNode] = false;
        return 1;
    }
}

int Trie::find(std::string_view str) {
    int CurrentNode = 0;
    for (auto letter : str) {
        if (!nextLetter[CurrentNode][letter]) {
            return 0;
        }
        CurrentNode = nextLetter[CurrentNode][letter];
    }
    if (wordEnd[CurrentNode]) {
        return 1;
    } else {
        return 0;
    }
}

void Trie::dfs(int CurrentNode, std::string& word, std::vector<std::string>& words) {
    for (int i = 0; i < CHARACTOR_LIMIT; i++) {
        if (nextLetter[CurrentNode][i]) {
            word.push_back(i);
            dfs(nextLetter[CurrentNode][i], word, words);
            word.pop_back();
        }
    }
    if (wordEnd[CurrentNode]) {
        words.push_back(word);
    }
}

std::vector<std::string> Trie::getWords() {
    std::vector<std::string> words;
    std::string word;
    for (int i = 0; i < CHARACTOR_LIMIT; i++) {
        if (nextLetter[0][i]) {
            word.push_back(i);
            dfs(nextLetter[0][i], word, words);
            word.pop_back();
        }
    }
    return words;
}

void Trie::clear() {
    memset(nextLetter, 0, sizeof(nextLetter));
    memset(wordEnd, 0, sizeof(wordEnd));
    nodeCount = 0;
}