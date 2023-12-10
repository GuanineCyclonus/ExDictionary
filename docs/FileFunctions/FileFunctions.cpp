#include <filesystem>
#include <fstream>
#include <iostream>
#include <string>
#include <string_view>

#include "Trie.h"
#include "FileFunctions.h"

std::filesystem::path path = std::string(std::filesystem::current_path());

void file::DirectoryCheck() {
    // std::cout << path << std::endl;
    if (!std::filesystem::exists(std::string(path) + "/WordLists")) {
        // std::filesystem::create_directory(path);
        std::filesystem::create_directories(std::string(path) + "/WordLists");
    }
    std::ifstream List(std::string(path) + "/WordLists/List.exdlist", std::ios::app);
    List.close();
}

bool file::CreateWordList(std::string_view wordListName) {
    file::DirectoryCheck();
    std::ofstream List;
    List.open(std::string(path) + "/WordLists/List.exdlist", std::ios::app);
    if (List.is_open()) {
        List << wordListName << std::endl;
        List.close();
        return true;
    } else {
        return false;
    }
}
bool file::ShowWordList() {
    file::DirectoryCheck();
    std::ifstream List(std::string(path) + "/WordLists/List.exdlist", std::ios::in);
    if (List.is_open()) {
        std::string wordListName;
        std::vector<std::string> wordLists;
        while (List >> wordListName) {
            wordLists.push_back(wordListName);
        }
        List.close();
        if (wordLists.size() == 0) {
            std::cout << "No Word Lists." << std::endl;
            return false;
        } else {
            std::cout << "Word Lists:" << std::endl;
            for (auto wordList : wordLists) {
                std::cout << wordList << std::endl;
            }
            return true;
        }
        return true;
    } else {
        return false;
    }
}
bool file::LoadWordList(std::string_view wordListName) {
    file::DirectoryCheck();
    std::ifstream List(std::string(path) + "/WordLists/List.exdlist", std::ios::in);
    if (List.is_open()) {
        std::string wordListNameInFile;
        while (List >> wordListNameInFile) {
            if (wordListName == wordListNameInFile) {
                List.close();
                return true;
            }
        }
        List.close();
        return false;
    } else {
        return false;
    }
}
bool file::LoadWords(Trie *trie, std::string_view wordList) {
    file::DirectoryCheck();
    std::ifstream WordList(std::string(path) + "/WordLists/" + wordList.data() + ".exdict", std::ios::in);
    if (WordList.is_open()) {
        std::string word;
        while (WordList >> word) {
            bool success = trie->insert(word);
            if (success) {
                std::cout << "Successfully added word \"" << word << "\"." << std::endl;
            } else {
                std::cout << "Failed to add word \"" << word << "\". The Word Exists." << std::endl;
            }
        }
        WordList.close();
        return true;
    } else {
        return false;
    }
}

bool file::UpdateWordList(Trie *trie, std::string_view wordList) {
    file::DirectoryCheck();
    std::ofstream WordList(std::string(path) + "/WordLists/" + wordList.data() + ".exdict", std::ios::out);
    std::vector<std::string> words = trie->getWords();
    if (WordList.is_open()) {
        for (auto word : words) {
            WordList << word << std::endl;
        }
        WordList.close();
        return true;
    } else {
        return false;
    }
}

bool file::DeleteWordList(std::string_view wordListName) {
    file::DirectoryCheck();
    std::ifstream List(std::string(path) + "/WordLists/List.exdlist", std::ios::in);
    if (List.is_open()) {
        std::string wordListNameInFile;
        std::vector<std::string> wordLists;
        while (List >> wordListNameInFile) {
            if (wordListName != wordListNameInFile) {
                wordLists.push_back(wordListNameInFile);
            }
        }
        List.close();
        std::ofstream List(std::string(path) + "/WordLists/List.exdlist", std::ios::out);
        if (List.is_open()) {
            for (auto wordList : wordLists) {
                List << wordList << std::endl;
            }
            List.close();
            std::filesystem::remove(std::string(path) + "/WordLists/" + wordListName.data() + ".exdict");
            return true;
        } else {
            return false;
        }
    } else {
        return false;
    }
}
