struct TrieNode {
    TrieNode() : children(vector<TrieNode*>(26, nullptr)), isLeaf(false) {
    }
    ~TrieNode() {
        for(int i = 0; i <26; ++i) {
            delete children[i];
        }
    }
    vector<TrieNode*> children;
    bool isLeaf;
};

class Trie {
public:
    Trie() : m_root(new TrieNode()) {    
    }
    ~Trie() {
        delete m_root;
    }
    void insert(const string& word) {
        TrieNode* ptr = m_root;
        for(const char c : word) {
            const int index = c - 'a';
            if(!ptr->children[index]) {
                ptr->children[index] = new TrieNode();
            }  
            ptr = ptr->children[index];
        }
        ptr->isLeaf = true;
    }
    bool searchWord(const string& word) {
        TrieNode* ptr = m_root;
        return onSearchWord(word, ptr, 0);
    }
private: 
    bool onSearchWord(const string& word, TrieNode* ptr, int startIndex) {
        if(startIndex == word.size()) {
            return ptr->isLeaf;
        }
        else if(word[startIndex] == '.') {
            for(const auto& child : ptr->children) { 
                if(child &&
                   onSearchWord(word, child, startIndex +1)) { 
                    return true;
                }
            }
            return false;
        }
        else if (ptr->children[word[startIndex] - 'a']) {
            return onSearchWord(word, 
                                ptr->children[word[startIndex] - 'a'], startIndex + 1);
        }
        return false;
    }
private:
    TrieNode* m_root;
};

class WordDictionary {
public:
    /** Initialize your data structure here. */
    WordDictionary() : m_trie(new Trie()) {
    }
    ~WordDictionary() {
        delete m_trie;
    }
    /** Adds a word into the data structure. */
    void addWord(string word) {
        m_trie->insert(word);
    }
    /** Returns if the word is in the data structure. A word could contain the dot character '.' to represent any one letter. */
    bool search(string word) {
        return m_trie->searchWord(word);
    }
private:
    Trie* m_trie;
};
