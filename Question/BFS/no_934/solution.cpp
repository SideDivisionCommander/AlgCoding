class Solution {
public:
    int shortestBridge(vector<vector<int>>& A)
    {
        if (A.size() <= 1 || A[0].size() <= 1) {
            return -1;
        }
        Init(A);
        while (!helpQue.empty()) {
            int size = helpQue.size();
            while (size > 0) {
                int row = helpQue.front().first;
                int col = helpQue.front().second;
                helpQue.pop();
                // tricky method to iter 4 directions {0, 1, 0, -1, 0}
                // tricky method to iter 8 directions {-1, -1, 0, -1, 1, 0, 1, 1, -1}
                vector<int> trickyArray = {0, 1, 0, -1, 0};
                for (int i = 0; i < 4; ++i) {
                    int nRow = row + trickyArray[i];
                    int nCol = col + trickyArray[i + 1];
                    if (nRow < 0 || nRow >= A.size() || nCol < 0 || nCol >= A[0].size() || A[nRow][nCol] == 2) {
                        continue;
                    }
                    if (A[nRow][nCol] == 1) {
                        return steps;
                    }
                    helpQue.push(pair<int, int>(nRow, nCol));
                    A[nRow][nCol] = 2;
                }
                size--;
            }
            steps++;
        }
        return -1;
    }
private:
    queue<pair<int, int>> helpQue;
    int steps;
    void Dfs(int row, int col, vector<vector<int>>& A)
    {
        if (row < 0 || row >= A.size() || col < 0 || col >= A[0].size() || A[row][col] == 0 || A[row][col] == 2) {
            return;
        }
        helpQue.push(pair<int, int>(row, col));
        A[row][col] = 2;
        Dfs(row - 1, col, A);
        Dfs(row, col + 1, A);
        Dfs(row + 1, col, A);
        Dfs(row, col - 1, A);
    }
    
    void Init(vector<vector<int>>& A)
    {
        bool found = false;
        steps = 0;
        for (int i = 0; i < A.size(); ++i) {
            for (int j = 0; j < A[0].size(); ++j) {
                if (A[i][j] != 0 && !found) {
                    // 通过Dfs去找到第一个岛屿里面的所有点，并加入到队列中
                    Dfs(i, j, A);
                    found = true;
                }
                if (found) {
                    return;
                } 
            }
        }   
        return;
    }
    
};