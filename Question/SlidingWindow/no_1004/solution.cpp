/*
滑动窗口    
*/
class Solution {
public:
    int longestOnes(vector<int>& A, int K) {
        int leftIndex = 0;
        int rightIndex = 0;
        int res = 0;
        for (; rightIndex < A.size(); rightIndex++) {
            if (A[rightIndex] == 0) {
                K--;
            }
            if (K < 0) {
                if (A[leftIndex] == 0) {
                    K++;
                }
                leftIndex++;
            }
        }
        res = rightIndex - leftIndex;
        return res;
    }
};