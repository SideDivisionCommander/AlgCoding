class Solution {
public:
    int lengthOfLongestSubstringTwoDistinct(string s) {
        if (Init(s) == 0) {
            return 0;
        }
        return Process(s);
    }
private:
    unordered_map<char, int> helpMap;
    int maxDis;
    
    int Init(string& s)
    {
        maxDis = 2;
        return s.size();
    }
    
    int Process(string& s)
    {
        int left = 0;
        int right = 0;
        int res = 0;
        
        while(right < s.size()) {
            if (helpMap.count(s[right]) > 0) {
                helpMap[s[right]]++;
                res = max(res, right - left + 1);
                right++;
            } else {
                if (helpMap.size() < maxDis) {
                    helpMap.insert(pair<char, int>(s[right], 0));
                } else if (helpMap.size() == maxDis) {
                    if (helpMap[s[left]] > 1) {
                        helpMap[s[left]]--;
                    } else if (helpMap[s[left]] == 1) {
                        helpMap.erase(s[left]);
                    }
                    left++;
                }
            }
        }
        return res;
    }
};