/*
 单调递减栈，栈内存index
 把数组复制一份，应对循环
*/
class Solution {
public:
    vector<int> nextGreaterElements(vector<int>& nums) {
        vector<int> doubleNums(nums.size() * 2, 0);
        vector<int> doubleRes(nums.size() * 2, -1);
        for (int i = 0; i < 2; ++i) {
            for (int j = 0; j < nums.size(); ++j) {
                doubleNums[i * nums.size() + j] = nums[j];
            }
        }
        stack<int> monoDown;
        for (int i = 0; i < doubleNums.size(); ++i) {
            while (!monoDown.empty() && doubleNums[i] > doubleNums[monoDown.top()]) {
                int topIndex = monoDown.top();
                monoDown.pop();
                doubleRes[topIndex] = doubleNums[i];
            }
            monoDown.push(i);
        }
        vector<int> res;
        res.assign(doubleRes.begin(), doubleRes.begin() + nums.size());
        return res;
    }
};