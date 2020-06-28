class Trie {
public:
    #define MAX_ALPHABET 26
    /** Initialize your data structure here. */
    bool isWord;
    Trie* children[MAX_ALPHABET];
    Trie()
    {
        isWord = false;
        for (int i = 0; i < MAX_ALPHABET; ++i) {
            children[i] = NULL;
        }
    }
    
    /** Inserts a word into the trie. */
    void insert(string word)
    {
        Trie* tmpNode = this;
        for (auto ch : word) {
            if (tmpNode->children[ch - 'a'] == NULL) {
                Trie* obj = new Trie();
                tmpNode->children[ch - 'a'] = obj;
            }
            tmpNode = tmpNode->children[ch - 'a'];
        }
        tmpNode->isWord = true;
        return;
    }
    
    /** Returns if the word is in the trie. */
    bool search(string word) 
    {
        Trie* tmpNode = this;
        for (auto ch : word) {
            if (tmpNode->children[ch - 'a'] == NULL) {
                return false;
            }
            tmpNode = tmpNode->children[ch - 'a'];
        }
        if (tmpNode->isWord == true) {
            return true;
        }
        return false;
    }
    
    /** Returns if there is any word in the trie that starts with the given prefix. */
    bool startsWith(string prefix)
    {
        Trie* tmpNode = this;
        for (auto ch : prefix) {
            if (tmpNode->children[ch - 'a'] == NULL) {
                return false;
            }
            tmpNode = tmpNode->children[ch - 'a'];
        }
        return true;
    }
};

/**
 * Your Trie object will be instantiated and called as such:
 * Trie* obj = new Trie();
 * obj->insert(word);
 * bool param_2 = obj->search(word);
 * bool param_3 = obj->startsWith(prefix);
 */