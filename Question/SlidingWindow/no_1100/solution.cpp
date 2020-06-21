class Solution {
public:
    int numKLenSubstrNoRepeats(string S, int K)
    {
        if (Init(S) < K) {
            return 0;
        }
        return Process(S, K);
    }
private:
    unordered_map<char, int> helpMap;
    
    int Init(string& s)
    {
        return s.size();
    }
    
    int Process(string&s, int K)
    {
        int left = 0;
        int right = 0;
        int res = 0;
        for (; right < K; ++right) {
            if (helpMap.count(s[right]) > 0) {
                helpMap[s[right]]++;
                continue;
            }
            helpMap.insert(pair<char, int>(s[right], 0));
        }
        if (helpMap.size() == K) {
            res++;
        }
        while(right < s.size()) {
            if (helpMap[s[left]] > 0) {
                helpMap[s[left]]--;
            } else {
                helpMap.erase(s[left]);
            }
            left++;
            if (helpMap.count(s[right]) <= 0) {
                helpMap.insert(pair<char, int>(s[right], 0));
            } else {
                helpMap[s[right]]++;
            }
            right++;
            if (helpMap.size() == K) {
                res++;
            }
        }
        return res;
    }
};