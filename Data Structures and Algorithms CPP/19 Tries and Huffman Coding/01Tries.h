#include <vector>
#include <string>

class Trie;

class TrieNode
{
private:
    char data;
    bool isTerminal;
    TrieNode **children;

    friend class Trie;

public:
    TrieNode(char data = 0, bool isTerminal = false) : data(data), isTerminal(isTerminal)
    {
        children = new TrieNode*[26];
        for (int i = 0; i < 26; i++)
            children[i] = nullptr;
    }

    ~TrieNode()
    {
        for (int i = 0; i < 26; i++)
            delete children[i];
    }
};

class Trie
{
private:
    TrieNode *root;

    void insertWord(std::string word, TrieNode *root)
    {
        if (word.empty())
        {
            root->isTerminal = true;
            return;
        }
        int idx = word[0] - 'a';
        if (!root->children[idx])
            root->children[idx] = new TrieNode(word[0]);
        insertWord(word.substr(1), root->children[idx]);
    }

    TrieNode *searchWord(std::string word, TrieNode *root)
    {
        if (word.empty())
            return root;
        int idx = word[0] - 'a';
        if (!root->children[idx])
            return nullptr;
        return searchWord(word.substr(1), root->children[idx]);
    }

    void eraseWord(std::string word, TrieNode *root)
    {
        if (word.empty())
        {
            root->isTerminal = false;
            return;
        }
        int idx = word[0] - 'a';
        if (!root->children[idx])
            return;
        eraseWord(word.substr(1), root->children[idx]);
        if (!root->children[idx]->isTerminal)
        {
            for (int i = 0; i < 26; i++)
                if (root->children[idx]->children[i])
                    return;
            delete root->children[idx];
            root->children[idx] = nullptr;
        }
    }

public:
    Trie() : root(new TrieNode()) {}

    Trie(TrieNode *root) : root(root) {}

    void insert(std::string word) { insertWord(word, root); }

    bool search(std::string word)
    {
        TrieNode *x = searchWord(word, root);
        return x ? x->isTerminal : false;
    }

    void erase(std::string word) { eraseWord(word, root); }

    TrieNode *searchWord_startsWith(std::string word) { return searchWord(word, root); }

    void fillWords(TrieNode *root, std::vector<std::string> &v, std::string word)
    {
        if (!root)
            return;
        if (root->isTerminal == true)
            v.push_back(word);
        word.push_back('a');
        for (int i = 0; i < 26; i++, word.back()++)
            fillWords(root->children[i], v, word);
    }
};