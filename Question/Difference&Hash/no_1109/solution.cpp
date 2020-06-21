/*
常规解法算法复杂度O(n^2)，会导致TLE
尝试优化到O(n)
*/


class Solution {
public:
    vector<int> corpFlightBookings(vector<vector<int>>& bookings, int n)
    {
        Init(n);
        /*
        for (auto b : bookings) {
            for (int j = b[0]; j <= b[1]; ++j) {
                helpVec[j] += b[2];
            }
        }
        helpVec.erase(helpVec.begin());
        */
        for (auto b : bookings) {
            helpVec[b[0]] += b[2];
            if (b[1] < n) {
                helpVec[b[1] + 1] -= b[2];
            }
        }
        for (int i = 1; i <= n; ++i) {
            helpVec[i] += helpVec[i - 1];
        }
        helpVec.erase(helpVec.begin());
        return helpVec;
    }
private:
    vector<int> helpVec;
    
    void Init(int n)
    {
        helpVec.assign(n + 1, 0);
        return;
    }
};