class Solution {
public:
    int longestValidParentheses(string s) {
        int result = 0;
        list<char> stack;
        stack.clear();
        list<char>::iterator it = stack.begin();
        for(int i = 0; i < s.length(); ++i){
            if(s[i] == '('){
                stack.push_back('(');
                continue;
            }
            if(!stack.empty()){
                stack.pop_back();
                result += 2;
            }
        }
        return result;
    }
};