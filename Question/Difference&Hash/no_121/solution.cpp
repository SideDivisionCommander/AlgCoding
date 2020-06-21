class Solution {
public:
    int maxProfit(vector<int>& prices)
    {
        if (prices.size() <= 1) {
            return 0;
        }
        Init();
        for (auto p : prices) {
            if (p < currMin) {
                currMin = p;
                continue;
            }
            maxCost = max(maxCost, p - currMin);
        }
        return maxCost;
    }
private:
    int currMin;
    int maxCost;
    
    void Init()
    {
        currMin = INT_MAX;
        maxCost = 0;
        return;
    }
};