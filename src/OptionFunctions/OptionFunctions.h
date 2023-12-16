#ifndef __OPTION_FUNCTIONS_H__
#define __OPTION_FUNCTIONS_H__

#include <string>
#include <string_view>
#include <vector>
#include "../Trie/Trie.h"

void AddWord(Trie* trie, const std::vector<std::string>& BUF);
void DeleteWord(Trie* trie, const std::vector<std::string>& BUF);
void FindWord(Trie* trie, const std::vector<std::string>& BUF);
void ListWords(Trie* trie);
void CreateWordList(const std::vector<std::string> &BUF);
void ShowWordList();
void LoadWordList(std::string_view wordList, std::string& wordListName);
void LoadWords(Trie* trie, const std::string& wordList);
void UpdateWordList(Trie* trie, const std::string& wordList);
void DeleteWordList(const std::vector<std::string>& BUF);

#endif // __OPTION_FUNCTIONS_H__