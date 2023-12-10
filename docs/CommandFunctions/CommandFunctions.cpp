#include <cstring>
#include <iostream>
#include <limits>
#include <new>
#include <ostream>
#include <string>
#include <string_view>
#include <vector>
#include "CommandFunctions.h"
#include "OptionFunctions.h"
#include "Trie.h"
#include "IOFunctions.h"

int commandCode;

void GetCommand() {
    std::string BUF;
    // int currentCommandCode;
    // std::cin >> currentCommandCode;
    // return currentCommandCode;
    std::cout << "> ";
    std::cin >> BUF; 
    commandCode = ConvertCommandToCode(BUF);
}

int ConvertCommandToCode(const std::string& BUF) {
    // std::cout << BUF << std::endl;
    if (BUF == EXIT) {
        return -1;
    } 
    else if (BUF == EDIT) {
        return 1;
    } 
    else if (BUF == REVIEW) {
        return 2;
    } 
    else if (BUF == RECITE) {
        return 3;
    } 
    else {
        return 0;
    }
};

void JumpToCertainMode() {
    switch (commandCode) {
        case -1:
            std::cout << "Exiting..." << std::endl;
            break;
        case 0:
            std::cout << "Unknown Command. Please enter again." << std::endl;
            break;
        case 1:
            std::cout << "Entering editing mode..." << std::endl;
            EditMode();
            break;
        case 2:
            std::cout << "Entering reviewing mode..." << std::endl;
            // ReviewMode();
            break;
        case 3:
            std::cout << "Entering reciting mode..." << std::endl;
            // ReciteMode();
            break;
        default:
            break;
    }
}

void EditMode() {
    std::vector<std::string> BUF;
    std::string wordList = std::string(EMPTY);
    Trie *trie = new Trie();
    std::cin.ignore(INT_MAX, '\n');
    std::cin.clear();
    while (true) {
        std::cout << wordList << " <- ";
        BUF = LineRead();
        if (BUF.empty()) {
            std::cout << "Unknown Command. Please enter again." << std::endl;
            continue;
        }
        if (BUF[0] == EXIT) {
            std::cout << "Exiting..." << std::endl;
            if (wordList != EMPTY) {
                UpdateWordList(trie, wordList);
            }
            delete trie;
            return;
        } 
        else if (BUF[0] == CREATE) {
            CreateWordList(BUF);
        }
        else if (BUF[0] == LOAD) {
            if ((int)BUF.size() > 2) {
                std::cout << "Cannot Load more than 1 word lists at the same time. Please enter again." << std::endl;
                continue;
            }
            LoadWordList(BUF[1], wordList);
            LoadWords(trie, wordList);
        }
        else if (BUF[0] == UNLOAD) {
            if (wordList == EMPTY) {
                std::cout << "Please load a word list first." << std::endl;
                continue;
            }
            UpdateWordList(trie, wordList);
            wordList = EMPTY;
            trie->clear();
        }
        else if (BUF[0] == LIST) {
            ShowWordList();
        }
        else if (BUF[0] == DELETELIST) {
            if (wordList != EMPTY) {
                std::cout << "Please unload the word list first." << std::endl;
                continue;
            }
            DeleteWordList(BUF);
        }
        else if (wordList == EMPTY && BUF[0] != LOAD) {
            std::cout << "Please load a word list first." << std::endl;
            continue;
        }
        else if (BUF[0] == ADD) {
            AddWord(trie, BUF);
        } 
        else if (BUF[0] == DELETE) {
            DeleteWord(trie, BUF);
        } 
        else if (BUF[0] == FIND) {
            FindWord(trie, BUF);
        } 
        else if (BUF[0] == LISTWORDS) {
            ListWords(trie);
        }
        else {
            std::cout << "Unknown Command. Please enter again." << std::endl;
        }
    }
    delete trie;
}
