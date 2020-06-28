class Solution {
public:
    string longestPalindrome(string s)
    {
        if (s.size() == 0) {
            return "";
        }
        Init(s);
        for (int i = 0; i < length; ++i) {
            int current = max(Process(i, i, s), Process(i, i + 1, s));
            if (current > longest) {
                longest = current;
                resStart = i - (current - 1) / 2;
            }
        }
        return s.substr(resStart, longest);
    }
private:
    int resStart;
    int longest;
    int length;
    void Init(string s)
    {
        length = s.size();
        resStart = 0;
        longest = 0;
    }
    
    int Process(int left, int right, string& s)
    {
        while(left >= 0 && right < length) {
            if (s[left] != s[right]) {
                break;
            }
            left--;
            right++;
        }
        return right - left - 1;
    }
};