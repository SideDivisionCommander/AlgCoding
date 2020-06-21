class Solution {
public:
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        if (numCourses == 1) {
            res.push_back(0);
            return res;
        }
        if (numCourses <= 0) {
            return res;
        }
        Init(numCourses, prerequisites);
        while(!zeroDegreeQue.empty()) {
            int node = zeroDegreeQue.front();
            zeroDegreeQue.pop();
            res.push_back(node);
            for (int i = 0; i < numCourses; ++i) {
                if (adj[node][i] > 0) {
                    adj[node][i]--;
                    inDegree[i]--;
                    if (inDegree[i] == 0) {
                        zeroDegreeQue.push(i);
                    }
                }
            }
        }
        if (res.size() != numCourses) {
            res.clear();
            return res;
        }
        return res;
    }
private:
    vector<vector<int>> adj;
    vector<int> inDegree;
    queue<int> zeroDegreeQue;
    vector<int> res;
    
    void Init(int n, vector<vector<int>>& vec)
    {
        adj.assign(n, vector<int>(n, 0));
        inDegree.assign(n, 0);
        res.clear();
        for (auto v : vec) {
            adj[v[1]][v[0]]++;
            inDegree[v[0]]++;
        }
        for (int i = 0; i < n; ++i) {
            if (inDegree[i] == 0) {
                zeroDegreeQue.push(i);    
            }
        }
        return;
    }
};