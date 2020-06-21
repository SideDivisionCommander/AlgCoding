/*
 该题并不是完全单调栈的实现，只是借鉴了单调栈的思路
 对于input[i]，任何input[i+n]，
 若input[i+n] >=input[i]
 则input[i+n]对于ramp是没作用的
 所以构造一个单调递减栈stack，把input入栈，
 再把input[i]与stack进行比较计算，算出ramp
*/
class Solution {
public:
    int maxWidthRamp(vector<int>& A) {
        Init(A);
        return GetMax(A);
    }
private:
    void Init(vector<int>& A)
    {
        for(int i = 0; i < A.size(); ++i) {
            if (helpStack.empty()) {
                helpStack.push(i);
                continue;
            }
            if (A[i] < A[helpStack.top()]) {
                helpStack.push(i);
            }
        }
        return;
    }
    
    int GetMax(vector<int>& A)
    {
        int res = 0;
        for (int i = A.size() - 1; i >= 0; --i) {
            while (!helpStack.empty() && A[i] >= A[helpStack.top()]) {
                res = max(res, i - helpStack.top());
                helpStack.pop();
            }
        }
        return res;
    }
    
    stack<int> helpStack;
}; 