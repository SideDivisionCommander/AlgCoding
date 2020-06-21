/*
 类似找到满足xx的最x的区间(子串，子数组)的xx，都可以优先考虑用滑动窗口法
*/
class Solution {
public:
    int lengthOfLongestSubstring(string s)
    {
        if (s.size() <= 0) {
            return 0;
        }
        return Process(s);
    }
private:
    unordered_set<char> helpSet;
    
    int Process(string& s)
    {
        int left = 0;
        int right = 0;
        int maxCost = 0;
        while(right <= s.size() - 1) {
            if (helpSet.count(s[right]) > 0) {
                helpSet.erase(s[left]);
                left++;
            } else {
                helpSet.insert(s[right]);
                maxCost = max(maxCost, right - left + 1);
                right++;
            }
        }
        return maxCost;
    }
};