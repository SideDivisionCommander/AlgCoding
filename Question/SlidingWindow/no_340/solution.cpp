class Solution {
public:
    int lengthOfLongestSubstringKDistinct(string s, int k) {
        if (s.size() <= 0 || k <= 0) {
            return 0;
        }
        return Process(s, k);
    }
private:
    unordered_map<char, int> helpMap;
    
    void EraseChar(char c)
    {
        if (helpMap.count(c) > 0 && helpMap[c] > 1) {
            helpMap[c]--;
            return;
        }
        if (helpMap.count(c) > 0 && helpMap[c] == 1) {
            helpMap.erase(c);
            return;
        }
        return;
    }
    
    int Process(string& s, int k)
    {
        int left = 0;
        int right = 0;
        int maxLength = 0;
        while(right <= s.size() - 1) {
             if (helpMap.count(s[right]) > 0) {
                 helpMap[s[right]]++;
                 maxLength = max(maxLength, right - left + 1);
                 right++;
             } else {
                 if (helpMap.size() < k) {
                     helpMap.insert(pair<char, int>(s[right], 1));
                     maxLength = max(maxLength, right - left + 1);
                     right++;                                
                 }else if (helpMap.size() == k) {
                     EraseChar(s[left]);
                     left++;
                 }
             }
        }
        return maxLength;
    }
};