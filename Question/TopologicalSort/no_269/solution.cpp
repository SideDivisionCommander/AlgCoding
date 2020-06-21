class Solution {
public:
    string alienOrder(vector<string>& words) 
    {
        if (!Init(words)) {
            return "";
        }
        Process();
        return res;
    }
private:
    unordered_map<char, unordered_set<char>> adjMap;
    unordered_map<char, int> inDegreeMap;
    queue<char> zeroDegreeQueue;
    string res;
    
    void HelpDegree(char a)
    {
        if (inDegreeMap.count(a) > 0) {
            inDegreeMap[a]++;
        } else {
            inDegreeMap.insert(pair<char, int>(a, 1));
        }
    }
    
    void HelpAdj(char a, char b)
    {
        if (adjMap.find(a) == adjMap.end()) {
            unordered_set<char> helpSet;
            helpSet.insert(b);
            adjMap.insert(pair<char, unordered_set<char>>(a, helpSet));
            HelpDegree(b);
        } else {
            if (adjMap[a].count(b) <= 0) {
                adjMap[a].insert(b);
                HelpDegree(b);
            }
        }
    }
    
    bool Init(vector<string>& words)
    {
        for (auto w : words) {
            for (auto c : w) {
                inDegreeMap.emplace(pair<char, int>(c, 0));
            }
        }
        
        for (int i = 0; i < words.size(); ++i) {
            for (int j = i + 1; j < words.size(); ++j) {
                // Check that word[j] is not a prefix of word[i].
                if (words[i].size() > words[j].size() && static_cast<int>(words[i].find(words[j])) == 0) {
                    return false;
                }
                int length = min(words[i].size(), words[j].size());
                int k = 0;
                for (; k < length; ++k) {
                    if (words[i][k] != words[j][k]) {
                        HelpAdj(words[i][k], words[j][k]);
                        break;
                    }
                }
            }
        }
        HelpQueue();
        return true;
    }
    
    void HelpQueue()
    {
        for (auto it = inDegreeMap.begin(); it != inDegreeMap.end(); ++it) {
            if (it->second == 0) {
                zeroDegreeQueue.push(it->first);
            }
        }
    }
    
    void Process()
    {
        while (!zeroDegreeQueue.empty()) {
            char node = zeroDegreeQueue.front();
            zeroDegreeQueue.pop();
            res.append(1, node);
            for (auto it = adjMap[node].begin(); it != adjMap[node].end(); ++it) {
                inDegreeMap[*it]--;
                if (inDegreeMap[*it] == 0) {
                    zeroDegreeQueue.push(*it);
                }
            }
        }
        if (res.size() != inDegreeMap.size()) {
            res.clear();
        }
    }
};