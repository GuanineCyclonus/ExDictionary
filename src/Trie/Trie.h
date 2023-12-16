#ifndef __TRIE_H__
#define __TRIE_H__

#include <string>
#include <string_view>
#include <vector>

static const int CHARACTOR_LIMIT = (1 << 8);
static const int NODE_LIMIT = (1 << 12);

class Trie {
    private:
        bool wordEnd[NODE_LIMIT];
        int nextLetter[NODE_LIMIT][CHARACTOR_LIMIT];
        int nodeCount;
    public:
        Trie();
        ~Trie();
        int insert(std::string_view str);
        int find(std::string_view str);
        int erase(std::string_view str);
        std::vector<std::string> getWords();
        void dfs(int CurrentNode, std::string& word, std::vector<std::string>& words);
        void clear();
};  

#endif