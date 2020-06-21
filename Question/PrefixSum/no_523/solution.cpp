class Solution {
public:
    bool checkSubarraySum(vector<int>& nums, int k) {
        Init(nums);
        if (nums.size() <= 1) {
            return false;
        }
        bool res = false;
        for (int i = 2; i < nums.size() + 1; ++i) {
            for (int j = 0; j < i - 1; ++j) {
                if (Check(prefixSum[i] - prefixSum[j], k)) {
                    return true;
                }
            }
        }
        return res;
    }
private:
    vector<int> prefixSum;
    
    void Init(vector<int>& nums)
    {
        prefixSum.assign(nums.size() + 1, 0);
        prefixSum[0] = 0;
        for (int i = 1; i < nums.size() + 1; ++i) {
            prefixSum[i] = prefixSum[i - 1] + nums[i - 1];
        }
        return;
    }
    
    bool Check(int num, int k)
    {
        if (k == 0) {
            if (num == 0) {
                return true;
            }
        } else {
            int num1 = num / k;
            int num2 = num % k;
            if (num2 == 0) {
                return true;
            }
        }
        return false;
    }
};