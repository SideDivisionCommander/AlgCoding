/*
 本题用贪心和DFS都无法解决问题，
 考虑采用大顶堆作为优先队列，
 总是走当前可走的最大权值路径
*/

class Solution {
public:
    int maximumMinimumPath(vector<vector<int>>& A) {
        Init(A);
        return Process(A);
    }
private:    
    vector<vector<int>> visited;
    struct Node {
        int row;
        int col;
        int value;
        Node(int r, int c, int v)
        {
            row = r;
            col = c;
            value = v;
        }
    };
    struct cmp {
        bool operator() (const Node& a, const Node& b) const
        {
            return a.value < b.value;
        }
    };
    priority_queue<Node, vector<Node>, cmp> que;
    
    void Init(vector<vector<int>>& A)
    {
        visited.assign(A.size(), vector<int>(A[0].size(), 0));
        Node n = Node(0, 0, A[0][0]);
        // cout << n.row << " " << n.col << " " << n.value << endl;
        que.push(n);
        visited[n.row][n.col] = 1;
        return;
    }
    
    int Process(vector<vector<int>>& A)
    {
        int res = INT_MAX;
        while(!que.empty()) {
            Node n = que.top();
            // cout << que.top().value << endl;
            que.pop();
            res = min(res, n.value);
            if (n.row == A.size() - 1 && n.col == A[0].size() - 1) {
                break;
            }
            PushNewEleIntoQue(A, n);
        }
        return res;
    }
    
    void PushNewEleIntoQue(vector<vector<int>>& A, Node n)
    {
        if (n.row - 1 >= 0 && visited[n.row - 1][n.col] == 0) {
            Node n1 = Node(n.row - 1, n.col, A[n.row - 1][n.col]);
            que.push(n1);
            visited[n.row - 1][n.col] = 1;
        }
        if (n.row + 1 <= A.size() - 1 && visited[n.row + 1][n.col] == 0) {
            Node n1 = Node(n.row + 1, n.col, A[n.row + 1][n.col]);
            que.push(n1);
            visited[n.row + 1][n.col] = 1;
        }
        if (n.col - 1 >= 0 && visited[n.row][n.col - 1] == 0) {
            Node n1 = Node(n.row, n.col - 1, A[n.row][n.col - 1]);
            que.push(n1);
            visited[n.row][n.col - 1] = 1;
        }
        if (n.col + 1 <= A[0].size() - 1 && visited[n.row][n.col + 1] == 0) {
            Node n1 = Node(n.row, n.col + 1, A[n.row][n.col + 1]);
            que.push(n1);
            visited[n.row][n.col + 1] = 1;
        }
        return;
    }
};