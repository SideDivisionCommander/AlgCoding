class Solution {
public:
    bool validTree(int n, vector<vector<int>>& edges) {
        Init(n);
        for (int i = 0; i < edges.size(); ++i) {
            if (edges[i][0] == edges[i][1]) {
                return false;
            } else if (FindRoot(edges[i][0]) == FindRoot(edges[i][1])) {
                return false;
            }
            Merge(edges[i][0], edges[i][1]);
        }
        if (!IsSingleTree()) {
            return false;
        }
        return true;
        
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
        while(preVec[num] != num) {
            num = preVec[num];
        }
        return num;
    }
    
    void Merge(int num1, int num2)
    {
        int root1 = FindRoot(num1);
        int root2 = FindRoot(num2);
        if (root1 < root2) {
            preVec[root2] = root1;
        } else if (root2 < root1) {
            preVec[root1] = root2;
        }
        return;
    }
    
    bool IsSingleTree()
    {
        int headNum = 0;
        for (int i = 0; i < preVec.size(); ++i) {
            if (preVec[i] == i) {
                headNum++;
            }
        }
        if (headNum > 1) {
            return false;
        }
        return true;
    }
};