class Solution {
public:
    int longestValidParentheses(string s) {
        int result = 0;
        list<int> stack1, stack2;
        stack1.clear();
        stack2.clear();
        for(int i = 0; i < s.length(); ++i){
            if(s[i] == '('){
                stack1.push_back(i);
                continue;
            }
            if(!stack1.empty()){
                stack1.pop_back();
                continue;
            }
            stack2.push_back(i);
        }
        stack1.merge(stack2);
        stack1.sort();
        int lastIndex = -1;
        for(list<int>::iterator it = stack1.begin(); it != stack1.end(); ++it){
            if (*it - lastIndex > result){
                result = *it - lastIndex;
            }
            lastIndex = *it;
        }
        if(0 == stack1.size()) return s.length();
        if(s.length() - stack1.back() > result) result = s.length() - stack1.back();
        return result - 1;
    }
};