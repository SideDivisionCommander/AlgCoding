/*
比较标准的并查集解法。
遍历所有egde，如果edge[0]和edge[1]指向同一个root则说明成环，
如果不指向同一个root则合并
*/
class Solution {
public:
    vector<int> findRedundantConnection(vector<vector<int>>& edges) {
        Init();
        for (int i = 0; i < edges.size(); ++i) {
            int num1 = edges[i][0];
            int num2 = edges[i][1];
            int root1 = FindRoot(num1);
            int root2 = FindRoot(num2);
            if (root1 == root2) {
                return edges[i];
            } else {
                Merge(root1, root2);
            }
        }
        return defaultVec;
    }
private:
    static constexpr int MAX_NUM = 1001;
    vector<int> pre;
    vector<int> defaultVec;
    void Init()
    {
        pre.assign(MAX_NUM, 0);
        defaultVec.assign(2, 0);
        for (int i = 1; i < MAX_NUM; ++i) {
            pre[i] = i;
        }
        return;
    }
    
    int FindRoot(int num)
    {
        while(pre[num] != num) {
            num = pre[num];
        }
        return num;
    }
    
    void Merge(int num1, int num2)
    {
        pre[num2] = num1;
    }
};