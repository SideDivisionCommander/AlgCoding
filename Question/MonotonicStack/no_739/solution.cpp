/*
解法一：
首先考虑最直观的解法，遍历T内的每个数字，
找到每个数字之后的数字中，第一个比它的数字的索引，
然后相减
这个解法用例虽然全过，但是超时
*/
/*
class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& T) {
        vector<int> res(T.size(), 0);
        for (int i = 0; i < T.size(); ++i) {
            for (int j = i+1; j < T.size(); ++j) {
                if (T[j] > T[i]) {
                    res[i] = j-i;
                    break;
                }
            }
        }
        return res;
    }
};
*/
/*
解法二：
利用单调栈可以将算法优化到O(n)，这里采用单调递减栈
将T内的数字索引逐个入栈，如果当前数字违反了单调递减的规律，
当前数字索引-栈顶数字索引 = 栈顶数字索引的结果
然后栈顶的数字索引出栈，当前数字索引入栈
*/
class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& T) {
        vector<int> res(T.size(), 0);
        stack<int> helper;
        for (int i = 0; i < T.size(); ++i) {
            if (helper.empty() || T[i] <= T[helper.top()]) {
                helper.push(i);
            } else {
                while (!helper.empty() && T[i] > T[helper.top()]) {
                    res[helper.top()] = i - helper.top();
                    helper.pop();
                }
                helper.push(i);
            }
        }
        return res;
    }
};