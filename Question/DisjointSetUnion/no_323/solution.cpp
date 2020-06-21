class Solution {
public:
    int countComponents(int n, vector<vector<int>>& edges) {
        Init(n);
        Union(edges);
        return Process(n);
    }
private:
    vector<int> preVec;
    
    void Init(int n)
    {
        for (int i = 0; i < n; ++i) {
            preVec.push_back(i);
        }
        return;
    }
    
    int FindRoot(int num)
    {
        while(num != preVec[num]) {
            num = preVec[num];
        }
        return num;
    }
        
    void Union(vector<vector<int>>& edges)
    {
        for (auto e : edges) {
            int root1 = FindRoot(e[0]);
            int root2 = FindRoot(e[1]);
            if (root1 < root2) {
                preVec[root2] = root1;
            } else if (root2 < root1) {
                preVec[root1] = root2;
            }
        }
        return;
    }
    
    int Process(int n)
    {
        int res = 0;
        for (int i = 0; i < n; ++i) {
            if (preVec[i] == i) {
                res++;
            }
        }
        return res;
    }
};