/*
该题由于有负数，不适合用滑动窗口法，考虑用前缀和优化暴力解
*/
class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        Init(nums);
        int res = 0;
        for (int i = 1; i < nums.size() + 1; ++i) {
            for (int j = 0; j < i; ++j) {
                if (prefixSum[i] - prefixSum[j] == k) {
                    res++;
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
        prefixSum[0] = 0; //最前面填补一个0方便计算
        for (int i = 1; i < nums.size() + 1; ++i) {
            prefixSum[i] = prefixSum[i - 1] + nums[i - 1];
        }
        return;
    }
};