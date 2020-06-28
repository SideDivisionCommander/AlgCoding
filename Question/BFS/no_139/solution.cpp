/*BFS的对象是字符串分割的位置*/
class Solution {
public:
    bool wordBreak(string s, vector<string>& wordDict)
    {
        if (wordDict.size() == 0) {
            return false;
        }
        unordered_set<string> wordSet(wordDict.begin(), wordDict.end());
        Init(s);
        while(!helpQue.empty()) {
            int curr = helpQue.front();
            helpQue.pop();
            for (int i = curr + 1; i <= s.size(); ++i) {
                if (!visit[i] && wordSet.count(s.substr(curr, i - curr)) > 0) {
                    if (i == s.size()) {
                        return true;
                    } else {
                        helpQue.push(i);
                        visit[i] = true;
                    }   
                }
            }
        }
        return false;
    }
private:
    queue<int> helpQue;
    vector<bool> visit;
    void Init(string& s)
    {
        helpQue.push(0);
        visit.assign(s.size() + 1, false);
        visit[0] = true;
        return;
    }
    
};
/*该解法TLE*/
/*
class Solution {
public:
    bool wordBreak(string s, vector<string>& wordDict)
    {
        if (wordDict.size() == 0) {
            return false;
        }
        Init();
        while(!helpQue.empty()) {
            Node n = helpQue.front();
            helpQue.pop();
            if (s == (n.preStr + n.word)) {
                return true;
            }
            for (auto w : wordDict) {
                if (WordConnect(n.preStr + n.word, w, s)) {
                    Node tmpNode(n.preStr + n.word, w);
                    helpQue.push(tmpNode);
                }
            }
        }
        return false;
    }
private:
    struct Node {
        string preStr;
        string word;
        Node(string pre, string w)
        {
            preStr = pre;
            word = w;
        }
    };
    queue<Node> helpQue;
    void Init()
    {
        Node n("", "");
        helpQue.push(n);
        return;
    }
    bool WordConnect(string str1, string str2, string& s)
    {
        string tmpStr = str1 + str2;
        if (tmpStr.size() > s.size()) {
            return false;
        }
        if (tmpStr.empty()) {
            return true;
        }
        size_t found = s.find(tmpStr);
        if (found != string::npos && static_cast<int>(found) == 0) {
            return true;
        }
        return false;
    }
};
*/