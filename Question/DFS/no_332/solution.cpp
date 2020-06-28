/*
 该题可以使用递归完成，思路是，每次都尽量取最大的硬币，
 如果不行则取小一点的硬币，但是估计会超时
 使用动态规划，参考了思路：https://www.cnblogs.com/grandyang/p/5138186.html
 设dp[i] (0<=i<=n) amount为i时的最小找零数
 dp[0] = 0 
 dp[i] = min(dp[i], dp[i-coins[j]]+1) 1<=i<=n，0<=j<coins.size()
 该题与第279题有很相似的地方，都是要在dp推导的时候遍历，
 且反复更新同一dp[i]的值取最小
*/

class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
        if (amount == 0) {
            return 0;
        }
        if (coins.size() < 1 || amount < 0) {
            return -1;
        }
        vector<int> dp(amount + 1, INT_MAX);
        dp[0] = 0;    
        for (int i = 1; i <= amount; ++i) {
            for (int j = 0; j < coins.size(); ++j) {
                if (i - coins[j] >= 0 && dp[i-coins[j]] != INT_MAX) {
                    dp[i] = min(dp[i], dp[i-coins[j]]+1);    
                }
            }
        }
        if (dp[amount] == INT_MAX) {
            return -1;
        }
        return dp[amount];
    }
};