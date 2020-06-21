/*
只计算增序序列的增益即可
*/
class Solution {
public:
    int maxProfit(vector<int>& prices)
    {
        if (prices.size() <= 1) {
            return 0;
        }
        Init(prices);
        for (int i = 1; i < expandInput.size(); ++i) {
            int profit = expandInput[i] - expandInput[i - 1];
            if (profit > 0) {
                sum += profit;
            }
        }
        return sum;
    }
private:
    int sum;
    vector<int> expandInput;
    void Init(vector<int>& prices)
    {
        sum = 0;
        // 数组头插一个极大值方便计算
        expandInput.push_back(INT_MAX);
        for (auto p : prices) {
            expandInput.push_back(p);
        }
        return;
    }
};