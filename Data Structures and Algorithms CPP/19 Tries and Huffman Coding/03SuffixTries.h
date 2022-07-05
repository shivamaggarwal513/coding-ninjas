#include <string>

class SuffixTrie;

class SuffixTrieNode
{
private:
    char data;
    SuffixTrieNode **children;

    friend class SuffixTrie;

public:
    SuffixTrieNode(char data = 0) : data(data)
    {
        children = new SuffixTrieNode*[26];
        for (int i = 0; i < 26; i++)
            children[i] = nullptr;
    }

    ~SuffixTrieNode()
    {
        for (int i = 0; i < 26; i++)
            delete children[i];
    }
};

class SuffixTrie
{
private:
    SuffixTrieNode *root;

    void insertWord(std::string word, SuffixTrieNode *root)
    {
        if (word.empty())
            return;
        int idx = word[0] - 'a';
        if (!root->children[idx])
            root->children[idx] = new SuffixTrieNode(word[0]);
        insertWord(word.substr(1), root->children[idx]);
    }

    SuffixTrieNode *searchWord(std::string word, SuffixTrieNode *root)
    {
        if (word.empty())
            return root;
        int idx = word[0] - 'a';
        if (!root->children[idx])
            return nullptr;
        return searchWord(word.substr(1), root->children[idx]);
    }

    void eraseWord(std::string word, SuffixTrieNode *root)
    {
        if (word.empty())
            return;
        int idx = word[0] - 'a';
        if (!root->children[idx])
            return;
        eraseWord(word.substr(1), root->children[idx]);
        for (int i = 0; i < 26; i++)
            if (root->children[idx]->children[i])
                return;
        delete root->children[idx];
        root->children[idx] = nullptr;
    }

public:
    SuffixTrie() : root(new SuffixTrieNode()) {}

    SuffixTrie(SuffixTrieNode *root) : root(root) {}

    void insert(std::string word)
    {
        for (int i = 0; i < word.size(); i++)
            insertWord(word.substr(i), root);
    }

    bool search(std::string word) { return searchWord(word, root) ? true : false; }

    void erase(std::string word) { eraseWord(word, root); }
};

/* Not implemented:
 * void erase(std::string word)
 * remove word from suffix trie
 * also remove all suffixes of word
 * but don't remove those suffixes which were inserted as an independent word
 * or which were suffixes of some other independently inserted word
 */