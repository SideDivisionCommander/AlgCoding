/*
并查集，基本操作
*/
class Solution {
public:
    vector<int> pre;
    bool Init(int mSize)
    {
        if (mSize < 1) {
            return false;
        }
        for (int i = 0; i < mSize; i++) {
            pre.push_back(i);
        }
        return true;
    }
    
    int FindRoot(int i)
    {
        while (pre[i] != i) {
            i = pre[i];
        }
        return i;
    }

    int findCircleNum(vector<vector<int>>& M)
    {
        if (!Init(M.size())) {
            return 0;
        }
        int res = 0;
        // 遍历右上角的数组就可以获得朋友圈的关系
        for (int i = 0; i < M.size(); ++i) {
            for (int j = i + 1; j < M.size(); ++j) {
                if (M[i][j] == 1) {
                    int rootI = FindRoot(i);
                    int rootJ = FindRoot(j);
                    if (rootI != rootJ) {
                        pre[rootJ] = rootI;
                    }
                }
            }
        }
        // 获取朋友圈的数量
        for (int i = 0; i < M.size(); ++i) {
            if (FindRoot(i) == i) {
                res++;
            }
        }
        return res;
    }
};