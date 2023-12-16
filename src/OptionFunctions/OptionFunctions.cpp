#include <iostream>
#include <string>
#include <vector>
#include "OptionFunctions.h"
#include "../Trie/Trie.h"
#include "../FileFunctions/FileFunctions.h"

void AddWord(Trie* trie, const std::vector<std::string>& BUF) {
    auto it = BUF.begin() + 1;
    std::string word;
    while (it != BUF.end()) {
        word = *it;
        ++it;
        bool success = trie->insert(word);
        if (success) {
            std::cout << "Successfully added word \"" << word << "\"." << std::endl;
        } else {
            std::cout << "Failed to add word \"" << word << "\". The Word Exists." << std::endl;
        }
    }
}

void DeleteWord(Trie* trie, const std::vector<std::string>& BUF) {
    auto it = BUF.begin() + 1;
    std::string word;
    while (it != BUF.end()) {
        word = *it;
        ++it;
        bool success = trie->erase(word);
        if (success) {
            std::cout << "Successfully deleted word \"" << word << "\"." << std::endl;
        } else {
            std::cout << "Failed to delete word \"" << word << "\". The Word Doesn't Exist." << std::endl;
        }
    }
}

void FindWord(Trie *trie, const std::vector<std::string> &BUF) {
    auto it = BUF.begin() + 1;
    std::string word;
    while (it != BUF.end()) {
        word = *it;
        ++it;
        bool success = trie->find(word);
        if (success) {
            std::cout << "Successfully found word \"" << word << "\"." << std::endl;
        } else {
            std::cout << "Failed to find word \"" << word << "\". The Word Doesn't Exist." << std::endl;
        }
    }
}
void ListWords(Trie *trie) {
    std::vector<std::string> words = trie->getWords();
    if (!words.empty()) {
        std::cout << "Words in the word list:" << std::endl;
        for (auto word : words) {
            std::cout << word << std::endl;
        }
    } else {
        std::cout << "No words in the word list." << std::endl;
    }
}
void CreateWordList(const std::vector<std::string> &BUF) {
    auto it = BUF.begin() + 1;
    std::string wordListName;
    while (it != BUF.end()) {
        wordListName = *it;
        ++it;
        bool success = file::CreateWordList(wordListName);
        if (success) {
            std::cout << "Successfully created word list \"" << wordListName << "\"." << std::endl;
        } else {
            std::cout << "Failed to create word list \"" << wordListName << "\". The Word List Exists." << std::endl;
        }
    }
}

void ShowWordList() {
    bool success = file::ShowWordList();
    if (!success) {
        std::cout << "Failed to show word list." << std::endl;
    }
}

void LoadWordList(std::string_view wordList, std::string& wordListName) {
    bool success = file::LoadWordList(wordList);
    if (success) {
        std::cout << "Successfully loaded word list \"" << wordList << "\"." << std::endl;
        wordListName = wordList;
    } else {
        std::cout << "Failed to load word list \"" << wordList 
                  << "\". The Word List Doesn't Exist. Please create a word list." << std::endl;
    }
}

void LoadWords(Trie* trie, const std::string& wordList) {
    file::LoadWords(trie, wordList);
}

void UpdateWordList(Trie* trie, const std::string& wordList) {
    std::cout << "Unloading word list \"" << wordList << "\"..." << std::endl;
    file::UpdateWordList(trie, wordList);
}

void DeleteWordList(const std::vector<std::string> &BUF) {
    auto it = BUF.begin() + 1;
    std::string wordListName;
    while (it != BUF.end()) {
        wordListName = *it;
        ++it;
        bool success = file::DeleteWordList(wordListName);
        if (success) {
            std::cout << "Successfully deleted word list \"" << wordListName << "\"." << std::endl;
        } else {
            std::cout << "Failed to delete word list \"" << wordListName << "\". The Word List Doesn't Exist." << std::endl;
        }
    }
}