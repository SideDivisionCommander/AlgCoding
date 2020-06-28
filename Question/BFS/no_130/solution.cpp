class Solution {
public:
    void solve(vector<vector<char>>& board)
    {
        if (board.size() <= 2 || board[0].size() <= 2) {
            return;
        }
        Init(board);
        for (int i = 0; i < board.size(); i++) {
            for (int j = 0; j < board[0].size(); ++j) {
                if (IsBorderPoint(i, j, board) && !visit[i][j] && board[i][j] == 'O') {
                    Process(i, j, board);
                }
            }
        }
        PostProcess(board);
        return;
    }
private:
    struct Point {
        int row;
        int col;
        Point(int x, int y)
        {
            row = x;
            col = y;
        }
    };
    queue<Point> helpQue;
    vector<Point> modifyVec;
    vector<vector<bool>> visit;
    
    void Init(vector<vector<char>>& board)
    {
        visit.assign(board.size(), vector(board[0].size(), false));
    }
    
    bool IsBorderPoint(int row, int col, vector<vector<char>>& board)
    {
        if (row == 0 || row == board.size() - 1 || col == 0 || col == board[0].size() - 1) {
            return true;
        }
        return false;
    }
        
    void Process(int row, int col, vector<vector<char>>& board)
    {
        helpQue.push(Point(row, col));
        visit[row][col] = true;
        while (!helpQue.empty()) {
            Point p1 = helpQue.front();
            helpQue.pop();
            if (p1.row + 1 < board.size() && board[p1.row + 1][p1.col] == 'O' && !visit[p1.row + 1][p1.col]) {
                Point p2(p1.row + 1, p1.col);
                helpQue.push(p2);
                if (!IsBorderPoint(p2.row, p2.col, board)) {
                    modifyVec.push_back(p2);
                }
                visit[p2.row][p2.col] = true;
            }
            if (p1.col + 1 < board[0].size() && board[p1.row][p1.col + 1] == 'O' && !visit[p1.row][p1.col + 1]) {
                Point p2(p1.row, p1.col + 1);
                helpQue.push(p2);
                if (!IsBorderPoint(p2.row, p2.col, board)) {
                    modifyVec.push_back(p2);
                }
                visit[p2.row][p2.col] = true;
            }
            if (p1.row - 1 >= 0 && board[p1.row - 1][p1.col] == 'O' && !visit[p1.row - 1][p1.col]) {
                Point p2(p1.row - 1, p1.col);
                helpQue.push(p2);
                if (!IsBorderPoint(p2.row, p2.col, board)) {
                    modifyVec.push_back(p2);
                }
                visit[p2.row][p2.col] = true;
            }
            if (p1.col - 1 >= 0 && board[p1.row][p1.col - 1] == 'O' && !visit[p1.row][p1.col - 1]) {
                Point p2(p1.row, p1.col - 1);
                helpQue.push(p2);
                if (!IsBorderPoint(p2.row, p2.col, board)) {
                    modifyVec.push_back(p2);
                }
                visit[p2.row][p2.col] = true;
            }
        }
    }
    
    void PostProcess(vector<vector<char>>& board)
    {
        for (int i = 0; i < board.size(); i++) {
            for (int j = 0; j < board[0].size(); ++j) {
                if (!IsBorderPoint(i, j, board)) {
                    board[i][j] = 'X';
                }
            }
        }
        for (auto p : modifyVec) {
            board[p.row][p.col] = 'O';
        }
        return;
    }
};