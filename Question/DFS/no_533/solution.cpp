class Solution {
public:
    int findBlackPixel(vector<vector<char>>& picture, int N)
    {
        if (picture.size() == 0 || picture[0].size() == 0) {
            return 0;
        }
        Init(picture);
        for (int i = 0; i < picture.size(); ++i) {
            for (int j = 0; j < picture[0].size(); ++j) {
                if (picture[i][j] == 'B') {
                    if (Count(i, j, N, picture)) {
                        res++;
                    }
                }
            }
        }
        return res;
    }
private:
    vector<int> rowVec;
    vector<int> colVec;
    int res;
    void Init(vector<vector<char>>& picture)
    {
        rowVec.assign(picture.size(), 0);
        colVec.assign(picture[0].size(), 0);
        res = 0;
        for (int i = 0; i < picture.size(); ++i) {
            for (int j = 0; j < picture[0].size(); ++j) {
                if (picture[i][j] == 'B') {
                    rowVec[i]++;
                    colVec[j]++;
                }
            }
        }
        return;
    }
    
    bool Count(int row, int col, int N, vector<vector<char>>& picture)
    {
        if (rowVec[row] == colVec[col] && rowVec[row] == N) {
            vector<char> base(picture[0].size(), 'Z');
            for (int i = 0; i < picture.size(); ++i) {
                if (picture[i][col] == 'W') {
                    continue;
                }
                if (base[0] == 'Z') {
                    base = picture[i];
                } else {
                    if (picture[i] != base) {
                        return false;
                    }
                }
            }
            if (base[0] == 'Z') {
                return false;
            }
            return true;
        }
        return false;
    }
};