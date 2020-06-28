class Solution {
public:
    vector<vector<char>> updateBoard(vector<vector<char>>& board, vector<int>& click)
    {
        if (board.size() < 1 || board[0].size() < 1) {
            return board;
        }
        Init(board, click);
        while(!helpQue.empty()) {
            Point p1 = helpQue.front();
            helpQue.pop();
            UnrevealedBoard(p1, board);
            int x = p1.row;
            int y = p1.col;
            if (board[x][y] == 'B') {
                if ((x - 1 >= 0 && y - 1 >= 0) && !visit[x - 1][y - 1] && board[x - 1][y - 1] == 'E') {
                    Point p2(x - 1, y - 1);
                    helpQue.push(p2);
                    visit[x - 1][y - 1] = true;
                }
                if (x - 1 >= 0 && !visit[x - 1][y] && board[x - 1][y] == 'E') {
                    Point p2(x - 1, y);
                    helpQue.push(p2);
                    visit[x - 1][y] = true;
                }
                if ((x - 1 >= 0 && y + 1 < board[0].size()) && !visit[x - 1][y + 1] && board[x - 1][y + 1] == 'E') {
                    Point p2(x - 1, y + 1);
                    helpQue.push(p2);
                    visit[x - 1][y + 1] = true;
                }
                if (y - 1 >= 0 && !visit[x][y - 1] && board[x][y - 1] == 'E') {
                    Point p2(x, y - 1);
                    helpQue.push(p2);
                    visit[x][y - 1] = true;
                }
                if (y + 1 < board[0].size() && !visit[x][y + 1] && board[x][y + 1] == 'E') {
                    Point p2(x, y + 1);
                    helpQue.push(p2);
                    visit[x][y + 1] = true;
                }
                if ((x + 1 < board.size() && y - 1 >= 0) && !visit[x + 1][y - 1] && board[x + 1][y - 1] == 'E') {
                    Point p2(x + 1, y - 1);
                    helpQue.push(p2);
                    visit[x + 1][y - 1] = true;
                }
                if (x + 1 < board.size() && !visit[x + 1][y] && board[x + 1][y] == 'E') {
                    Point p2(x + 1, y);
                    helpQue.push(p2);
                    visit[x + 1][y] = true;
                }
                if ((x + 1 < board.size() && y + 1 < board[0].size()) && !visit[x + 1][y + 1] && board[x + 1][y + 1] == 'E') {
                    Point p2(x + 1, y + 1);
                    helpQue.push(p2);
                    visit[x + 1][y + 1] = true;
                }    
            }
        }
        return board;
    }
private:
    vector<vector<bool>> visit;
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
    void Init(vector<vector<char>>& board, vector<int>& click)
    {
        visit.assign(board.size(), vector(board[0].size(), false));
        Point p(click[0], click[1]);
        helpQue.push(p);
        visit[p.row][p.col] = true;
        return;
    }
    void UnrevealedBoard(Point p, vector<vector<char>>& board)
    {
        int numMine = 0;
        int x = p.row;
        int y = p.col;
        if (board[x][y] == 'M') {
            board[x][y] = 'X';
            return;
        }
        if ((x - 1 >= 0 && y - 1 >= 0) && board[x - 1][y - 1] == 'M') {
            numMine++;
        }
        if (x - 1 >= 0 && board[x - 1][y] == 'M') {
            numMine++;
        }
        if ((x - 1 >= 0 && y + 1 < board[0].size()) && board[x - 1][y + 1] == 'M') {
            numMine++;
        }
        if (y - 1 >= 0 && board[x][y - 1] == 'M') {
            numMine++;
        }
        if (y + 1 < board[0].size() && board[x][y + 1] == 'M') {
            numMine++;
        }
        if ((x + 1 < board.size() && y - 1 >= 0) && board[x + 1][y - 1] == 'M') {
            numMine++;
        }
        if (x + 1 < board.size() && board[x + 1][y] == 'M') {
            numMine++;
        }
        if ((x + 1 < board.size() && y + 1 < board[0].size()) && board[x + 1][y + 1] == 'M') {
            numMine++;
        }
        if (numMine >= 1) {
            board[x][y] = '0' + numMine;
        } else {
            board[x][y] = 'B';
        }
        return;
    }
};