#ifndef __FILE_FUNCTIONS_H__
#define __FILE_FUNCTIONS_H__

#include <filesystem>
#include <string>
#include <string_view>

#include "Trie.h"

namespace file {
    void DirectoryCheck();
    bool CreateWordList(std::string_view wordListName);
    bool ShowWordList();
    bool LoadWordList(std::string_view wordListName);
    bool LoadWords(Trie *trie, std::string_view wordList);
    bool UpdateWordList(Trie *trie, std::string_view wordList);
    bool DeleteWordList(std::string_view wordListName);
} // namespace file

extern std::filesystem::path path;

#endif // __FILE_FUNCTIONS_H__