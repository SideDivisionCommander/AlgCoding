class Solution {
public:
    vector<string> restoreIpAddresses(string s)
    {
        if (s.size() < 1 || s.size() > 12) {
            resStr.clear();
            return resStr;
        }
        string reaminStr;
        Helper(reaminStr, s, 4);
        return resStr;
    }
private:
    vector<string> resStr;
    
    bool IsStrValid(string str)
    {
        if (str.empty()) {
            return false;
        }
        if (str.size() >= 2 && str[0] == '0') {
            return false;
        }
        if (stoi(str) >= 0 && stoi(str) <= 255) {
            return true;
        }
        return false;
    }
    
    string BuildStr(string str1, string str2)
    {
        str1.append(1, '.');
        str2.append(str1);
        return str2;
    }
    
    void Helper(string formatStr, string restStr, int segment)
    {
        if (segment == 1) {
            if (!IsStrValid(restStr)) {
                return;
            }
            formatStr.append(restStr);
            resStr.push_back(formatStr);
        } else {
            for (int i = 1; i <= 3; ++i) {
                if (i > restStr.size()) {
                    continue;
                }
                string str1 = restStr.substr(0, i);
                string str2 = restStr.substr(i);
                if (!IsStrValid(str1)) {
                    continue;
                } else {
                    string helpStr = BuildStr(str1, formatStr);
                    Helper(helpStr, str2, segment - 1);
                }
            }
        }
        return;
    }
};