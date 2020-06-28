class Solution {
public:
    int calculate(string s)
    {
        StepOne(s);
        return StepTwo();
    }
private:
    stack<string> helpStack;
    
    void InsertSym(char c)
    {
        string sym;
        sym.append(1, c);
        helpStack.push(sym);
        return;
    }    
    
    string CalcMulti(string num1, string num2)
    {
        return to_string(stoi(num1) * stoi(num2));
    }
    
    string CalcDiv(string num1, string num2)
    {
        return to_string(stoi(num1) / stoi(num2));
    }
    
    void Process(string& tmpStr)
    {
        if (!helpStack.empty() && helpStack.top().compare("*") == 0) {
            helpStack.pop();
            string num = helpStack.top();
            helpStack.pop();
            string multiNum = CalcMulti(num, tmpStr);
            helpStack.push(multiNum);
        } else if (!helpStack.empty() && helpStack.top().compare("/") == 0) {
            helpStack.pop();
            string num = helpStack.top();
            helpStack.pop();
            string divNum = CalcDiv(num, tmpStr);
            helpStack.push(divNum);
        } else {
            helpStack.push(tmpStr);
        }
    }
    
    void StepOne(string& s)
    {
        string tmpStr;
        for (auto c : s) {
            if (c == ' ') {
                continue;
            }
            if (c >= '0' && c <= '9') {
                tmpStr.append(1, c);
                continue;
            } else {
                Process(tmpStr);
                InsertSym(c);
                tmpStr.clear();
            }
        }
        Process(tmpStr);
        return;
    }
    
    int StepTwo()
    {
        int res = 0;
        string lastNum;
        while(!helpStack.empty()) {
            string cStr = helpStack.top();
            helpStack.pop();
            if (cStr.compare("-") == 0) {
                int num = 0 - stoi(lastNum);
                res += num;
                continue;
            }
            if (cStr.compare("+") == 0) {
                int num = stoi(lastNum);
                res += num;
                continue;
            }
            lastNum = cStr;
        }
        if (!lastNum.empty()) {
            res += stoi(lastNum);
        }
        return res;
    }
};