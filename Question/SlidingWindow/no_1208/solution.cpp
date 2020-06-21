/*
 本题首先考虑是否可以使用动态规划，但是仔细推敲发现并不能使用
 其次考虑暴力法，肯定可以完成，但是复杂度过高，有可能性能用例不过
 再考虑，滑动窗口法，窗口的长度是变长的。
 开始时，将窗口的左右指针都放置在字符串的位置0，然后开始遍历
 如果当前的窗口内的 cost <= maxCost 则 右指针右移，再计算
 如果当前的窗口内的 cost > maxCost  则 左指针右移，再计算
 迭代计算出最宽的窗口值。
*/
class Solution {
public:
    int equalSubstring(string s, string t, int maxCost) {
        int windowLeft = 0;
        int windowRight = 0;
        int cost = 0;
        int maxRes = 0;
        int res = 0;
       
        while(windowRight <= s.size()-1 && windowLeft <= s.size()-1) {
            cost += abs(s[windowRight]-t[windowRight]);
            if (cost <= maxCost) {
                res = windowRight - windowLeft + 1;
                maxRes = max(res, maxRes);
               
            } else {
                cost -= abs(s[windowLeft]-t[windowLeft]);
                windowLeft++;
            }
            windowRight++;
        }
        return maxRes;
    }
};