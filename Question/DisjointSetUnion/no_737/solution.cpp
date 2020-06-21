class Solution {
public:
    bool areSentencesSimilarTwo(vector<string>& words1, vector<string>& words2, vector<vector<string>>& pairs) {
        Init(pairs, words1, words2);
        return Process(words1, words2);
    }
    
private:
    void Init(vector<vector<string>>& pairs, vector<string>& words1, vector<string>& words2)
    {
        for (auto w : words1) {
            preMap.emplace(pair<string, string>(w, w));
        }
        for (auto w : words2) {
            preMap.emplace(pair<string, string>(w, w));
        }
        for (auto p : pairs) {
            // preMap.emplace(pair<string, string>(p[0], p[0]));
            // preMap.emplace(pair<string, string>(p[1], p[1]));
            Merge(p[0], p[1]);
        }
        return;
    }
    
    bool Process(vector<string>& words1, vector<string>& words2)
    {
        bool flag = true;
        if (words1.size() != words2.size()) {
            return false;
        }
        for (int i = 0; i < words1.size(); ++i) {
            string root1 = FindRoot(words1[i]);
            string root2 = FindRoot(words2[i]);
            if (root1.compare(root2) != 0) {
                flag = false;
            }
        }
        return flag;
    }
    
    void Merge(string s1, string s2)
    {
        string root1 = FindRoot(s1);
        string root2 = FindRoot(s2);
        if (root1.compare(root2) > 0) {
            preMap[root1] = root2;
            return;
        }
        if  (root1.compare(root2) < 0) {
            preMap[root2] = root1;
            return;
        }
        return;
    }
    
    string FindRoot(string s)
    {
        while (preMap[s].compare(s) != 0) {
            s = preMap[s];
        }
        return s;
    }
    
    unordered_map<string, string> preMap;
};