class Solution {
public:
    #define MAX_ALPHBET 26
    struct TrieNode {
        bool isWord;
        TrieNode* children[MAX_ALPHBET];
    };
    
    struct TrieNode* Create()
    {
        struct TrieNode* root = new TrieNode();
        root->isWord = false;
        for (int i = 0; i < 26; ++i) {
            root->children[i] = NULL;
        }
        return root;
    }
    
    void Insert(struct TrieNode* root, string word)
    {
        struct TrieNode* currNode = root;
        for (auto ch : word) {
            if (currNode->children[ch - 'a'] == NULL) {
                struct TrieNode* newNode = Create();
                currNode->children[ch - 'a'] = newNode;
            }
            currNode = currNode->children[ch - 'a'];
        }
        currNode->isWord = true;
    }
    
    string Prefix(struct TrieNode* root, string word)
    {
        struct TrieNode* currNode = root;
        string strRst;
        strRst.clear();
        for(int i = 0; i < word.size(); ++i) {
            if (currNode->children[word[i] - 'a'] != NULL) {
                currNode = currNode->children[word[i] - 'a'];
                if (currNode->isWord) {       
                    strRst = word.substr(0, i + 1);
                    break;
                }
            } else {
                break;
            }
        }
        return strRst;
    }
    
    // String split
    vector<string> Split(string str, string pattern)
    {
        string::size_type pos;
        vector<string> result;
        str += pattern; // extend string for east manipluting
        int size = str.size();
        for (int i = 0; i < size; i++) {
            pos = str.find(pattern, i);
            if (pos < size) {
                string s = str.substr(i, pos - i);
                result.push_back(s);
                i = pos + pattern.size() - 1;
            }
        }
        return result;
    }
    
    string replaceWords(vector<string>& dict, string sentence) {
        struct TrieNode* root = Create();
        for (auto str : dict) {
            Insert(root, str);
        }
        vector<string> rstVec;
        rstVec.clear();
        rstVec = Split(sentence, " ");
        string rst;
        rst.clear();
        for (auto str : rstVec) {
            string prefixStr = Prefix(root, str);
            if (!prefixStr.empty()) {
                rst += (prefixStr + " ");
            } else {
                rst += (str + " ");
            }
        }
        // Remove the last space in the string
        if (!rst.empty()) {
            rst = rst.substr(0, rst.size() - 1);
        }
        return rst;
    }
};