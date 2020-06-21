class Solution {
public:
    int minSwaps(vector<int>& data)
    {
        Init(data);
        if (totalOne == 0) {
            return 0;
        }
        return Process(data);
    }
private:
    int totalOne;
    
    void Init(vector<int>& data)
    {
        totalOne = 0;
        for (auto n : data) {
            if (n == 1) {
                totalOne++;
            }
        }
        return;
    }
    
    int Process(vector<int>& data)
    {
        int left = 0;
        int right = 0;
        int oneCount = 0;
        int zeroCount = 0;
        int res = INT_MAX;
        while(right < data.size()) {
            if (oneCount + zeroCount < totalOne) {
                if (data[right] == 1) {
                    oneCount++;
                }
                if (data[right] == 0) {
                    zeroCount++;
                }
                right++;
            } else if (oneCount + zeroCount == totalOne) {
                res = min(res, zeroCount);
                if (data[left] == 0) {
                    zeroCount--;
                }
                if (data[left] == 1) {
                    oneCount--;
                }
                left++;
            }
        }
        if (res == INT_MAX) {
            return 0;
        }
        return res;
    }
};