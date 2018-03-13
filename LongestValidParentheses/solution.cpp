class Solution {
public:
    /*
    [Algorithm]
    To write down every index of "(" or ")" that not matched,
    then sort them, finally, get the largest interval, and that's
    the answer.
    [Performance]
    16ms for all test case, not so good, beat only 10%.
    */
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
/*
class Solution {
public:
    
    //[Algorithm]
    //Leave every unmatched "(" or ")" in the stack,
    //calculate current valid length by (current index - index in the top of the stack) 
    //[Performance]
    //15ms for all test case, not so good, beat only 13%.

    int longestValidParentheses(string s) {
        int result = 0;
        list<int> stack1;
        stack1.clear();
        stack1.push_back(-1);
        for(int i = 0; i < s.length(); ++i){
            if(s[i] == '('){
                stack1.push_back(i);
                continue;
            }
            else{
                stack1.pop_back();
                if(stack1.empty()){
                    stack1.push_back(i);
                }
                else{
                    result = max(result, i - stack1.back());
                }
            }
        }
        return result;
    }
    int max(int v1, int v2){
        return ( (v1 > v2) ? v1:v2 );
    }
};
*/