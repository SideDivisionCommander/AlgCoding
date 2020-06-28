class Solution {
public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList)
    {
        if (wordList.size() == 0) {
            return 0;
        }
        Init(beginWord, wordList);
        if (helpSet.count(endWord) == 0) {
            return 0;
        }
        while(!helpQueue.empty()) {
            Node node = helpQueue.front();
            helpQueue.pop();
            if (node.word == endWord) {
                return node.level;
            }
            // 这里的比较方法比较巧妙，考虑每次仅变动单词每一位上的单个char
            // 看是否能够在set中找到，找得到则视为一个相连路径
            // 之前想的方法是每次都把currWord和wordlist中所有的还没访问过的word
            // 做比较，看看是否不同的字母数，超过1，逻辑没问题，但是会TLE
            for (int i = 0; i < node.word.size(); ++i) {
                int c = node.word[i];
                for (int j = 'a'; j <= 'z'; ++j) {
                    node.word[i] = j;
                    if (helpSet.count(node.word) > 0) {
                        Node tmpNode(node.word, node.level + 1);
                        helpQueue.push(tmpNode);
                        helpSet.erase(node.word);
                    }
                    node.word[i] = c;
                }
            }
        }
        return 0;
    }
private:
    struct Node {
        string word;
        int level;
        Node(string w, int l)
        {
            word = w;
            level = l;
        }
    };
    queue<Node> helpQueue;
    unordered_set<string> helpSet;
    void Init(string word, vector<string>& wordList)
    {
        Node node(word, 1);
        helpQueue.push(node);
        for (auto w : wordList) {
            helpSet.emplace(w);    
        }
        return;
    }
};