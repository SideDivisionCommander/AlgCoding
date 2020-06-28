class Solution {
public:
    int findLonelyPixel(vector<vector<char>>& picture)
    {
        if (picture.size() == 0 || picture[0].size() == 0) {
            return 0;
        }
        Init();
        for (int row = 0; row < picture.size(); ++row) {
            for (int col = 0; col < picture[0].size(); ++col) {
                bool up = true;
                bool down = true;
                bool left = true;
                bool right = true;
                if (picture[row][col] == 'B') {
                    if (row - 1 >= 0) {
                        up = Dfs(row - 1, col, picture, 2);
                    }
                    if (row + 1 < picture.size()) {
                        down = Dfs(row + 1, col, picture, 4);
                    }
                    if (col - 1 >= 0) {
                        left = Dfs(row, col - 1, picture, 1);
                    }
                    if (col + 1 < picture[0].size()) {
                        right = Dfs(row, col + 1, picture, 3);
                    }
                    if (up && down && left && right) {
                        res++;
                    }
                }  
            }
        }
        return res;
    }
private:
    int res;
    
    void Init()
    {
        res = 0;
        return;
    }
    
    // left : 1, up : 2, right : 3, down : 4
    bool Dfs(int row, int col, vector<vector<char>>& picture, int direction)
    {
        if (row < 0 || 
            row >= picture.size() || 
            col < 0 || 
            col >= picture[0].size()) {
            return true;
        }
        if (picture[row][col] == 'B') {
            return false;
        }
        if (direction == 1) {
            return Dfs(row, col - 1, picture, 1);
        }
        if (direction == 3) {
            return Dfs(row, col + 1, picture, 3);
        }
        if (direction == 2) {
            return Dfs(row - 1, col, picture, 2);
        }
        if (direction == 4) {
            return Dfs(row + 1, col, picture, 4);
        }
        return false;
    }
};