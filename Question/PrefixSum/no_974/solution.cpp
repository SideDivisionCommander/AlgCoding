/*
 本体采用标准前缀和的做法，可以得到解答，时间复杂度为O(n^2)，但是性能TLE
 所以考虑，采用优化为O(n)的方法
*/
class Solution {
public:
    int subarraysDivByK(vector<int>& A, int K)
    {
        Init(A);
        int res = 0;
        /*
        for (int i = 1; i < A.size() + 1; ++i) {
            for (int j = 0; j < i; ++j) {
                if (Check(prefixSum[i] - prefixSum[j], K)) {
                    res++;
                }
            }
        }
        */
        for (int i = 0; i < A.size() + 1; ++i) {
            /* 不直接使用 prefixSum[i] % K 的原因是有负数的情况
            /  比如用例 [-1, 2, 9]  2
            /  这里比较难想到，可以重点记忆 */
            int key = (prefixSum[i] % K + K) % K;
            if (helpMap.count(key) > 0) {
                helpMap[key]++;
            } else {
                helpMap.insert(pair<int, int>(key, 1));
            }
        }
        for (auto it = helpMap.begin(); it != helpMap.end(); it++) {
            int count = (*it).second;
            if (count > 1) {
                res += (count * (count - 1) / 2); // C(count, 2) 组合数
            }
        }
        return res;
    }
private:
    vector<int> prefixSum;
    unordered_map<int, int> helpMap;
    void Init(vector<int>& A)
    {
        prefixSum.assign(A.size() + 1, 0);
        prefixSum[0] = 0;
        for (int i = 1; i < A.size() + 1; ++i) {
            prefixSum[i] = prefixSum[i - 1] + A[i - 1];
        }
        return;
    }
    /*
    bool Check(int num, int k)
    {
        if (k == 0) {
            if (num == 0) {
                return true;
            }
        } else {
            if (num % k == 0) {
                return true;
            }
        }
        return false;
    }
    */
};