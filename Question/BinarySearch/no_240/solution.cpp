class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target)
    {
        if (matrix.size() == 0) {
            return false;
        }
        // 在对每一行做二分查找之前，先找出目标值所在行的上限。
        int top = 0;
        int bottom = matrix.size() - 1;
        while(top < bottom) {
            int middle = top + ((bottom - top) >> 1);
            if (matrix[middle][0] > target) {
                bottom = middle - 1;
                continue;
            }
            if (matrix[middle][0] < target) {
                top = middle + 1;
                continue;
            } 
            return true;
        }
        for (int i = 0; i <= bottom; ++i) {
            if (Found(matrix[i], target)) {
                return true;
            }
        }
        return false;
    }
private:
    bool Found(vector<int> m, int target)
    {
        if (m.size() == 0) {
            return false;
        }
        int left = 0;
        int right = m.size() - 1;
        while(left <= right) {
            int middle = left + ((right - left) >> 1);
            if (m[middle] > target) {
                right = middle - 1;
                continue;
            }
            if (m[middle] < target) {
                left = middle + 1;
                continue;
            }
            return true;
        }
        return false;
    }
};