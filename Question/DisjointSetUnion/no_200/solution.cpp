class Solution {
public:
    int numIslands(vector<vector<char>>& grid) {
        if (grid.size() == 0 || grid[0].size() == 0) {
            return 0;
        }
        Init(grid);
        for (int i = 0; i < exGrid.size(); ++i) {
            for (int j = 0; j < exGrid[0].size(); ++j) {
                if (exGrid[i][j] == '1') {
                    if (exGrid[i][j - 1] == '1') {
                        pair<int, int> root1 = FindRoot(pair<int, int>(i, j));
                        pair<int, int> root2 = FindRoot(pair<int, int>(i, j - 1)); 
                        Merge(root1, root2);
                    }
                    if (exGrid[i - 1][j] == '1') {
                        pair<int, int> root1 = FindRoot(pair<int, int>(i, j));
                        pair<int, int> root2 = FindRoot(pair<int, int>(i - 1, j)); 
                        Merge(root1, root2);
                    }
                }
            }
        }
        return PostProcess();
    }
private:
    vector<vector<char>> exGrid;
    vector<vector<pair<int, int>>> pre;
    void Init(vector<vector<char>>& grid)
    {
        exGrid.assign(grid.size() + 2, vector<char>(grid[0].size() + 2, '0'));
        pre.assign(grid.size() + 2, vector<pair<int, int>>(grid[0].size() + 2, pair<int, int>(0, 0)));
        for (int i = 0; i < grid.size() + 2; ++i) {
            for (int j = 0; j < grid[0].size() + 2; ++j) {
                if (i == 0 || i == grid.size() + 1) {
                    exGrid[i][j] = '0';
                } else {
                    if (j == 0 || j == grid[0].size() + 1) {
                        exGrid[i][j] = '0';
                    } else {
                        exGrid[i][j] = grid[i - 1][j - 1];
                        pre[i][j] = pair<int, int>(i, j);
                    }
                }
            }
        }
        return;
    }
    
    pair<int, int> FindRoot(pair<int, int> p)
    {
        while(p != pre[p.first][p.second]) {
            p = pre[p.first][p.second];
        }
        return p;
    }
    
    void Merge(pair<int, int> root1, pair<int, int> root2)
    {
        if (root1 == root2) {
            return;
        } else {
            pre[root1.first][root1.second] = root2;
        }
        return;
    }
    
    int PostProcess()
    {
        int res = 0;
        for (int i = 0; i < pre.size(); ++i) {
            for (int j = 0; j < pre[0].size(); ++j) {
                if (exGrid[i][j] == '1' && pre[i][j] == pair<int, int>(i, j)) {
                    res++;
                }
            }
        }
        return res;
    }
};