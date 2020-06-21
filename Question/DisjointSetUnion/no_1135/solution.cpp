/*
几个图的概念定义：
连通图：在无向图中，若任意两个顶点vivi与vjvj都有路径相通，则称该无向图为连通图。
强连通图：在有向图中，若任意两个顶点vivi与vjvj都有路径相通，则称该有向图为强连通图。
连通网：在连通图中，若图的边具有一定的意义，每一条边都对应着一个数，称为权；
        权代表着连接连个顶点的代价，称这种连通图叫做连通网。
生成树：一个连通图的生成树是指一个连通子图，它含有图中全部n个顶点，但只有足以构成一棵树的n-1条边。
        一颗有n个顶点的生成树有且仅有n-1条边，如果生成树中再添加一条边，则必定成环。
最小生成树：在连通网的所有生成树中，所有边的代价和最小的生成树，称为最小生成树。
本题属于最小生成树的范畴，可以采用Kruskal算法，如下：
此算法可称为“加边法”，
初始最小生成树的边数为0，
每迭代一次就选择一条满足条件的最小代价边，加入到最小生成树的边集合里
1. 把图中所有的边按代价从小到大排序；
2. 把途中的n个顶点看成独立的n棵树组成的森林；
3. 按权值从小到大选择边，所选的边连接的两个顶点，应该属于两颗不同的树，则成为最小生成树的一条边，并将这两棵
   树合并为一棵树。
4. 重复（3），直到所有顶点都在一棵树内或者有n-1条边为止。
*/
class Solution {
public:
    int minimumCost(int N, vector<vector<int>>& connections)
    {
        Init(N);
        vector<vector<int>> sortedVec = HelpSort(connections);
        int res = 0;
        for (auto v : sortedVec) {
            if (v[0] == v[1]) {
                continue;
            }
            if (FindRoot(v[0]) != FindRoot(v[1])) {
                Merge(v[0], v[1]);
                res += v[2];
            }
        }
        if (!ExistWay(N)) {
            return -1;
        }
        return res;
    }
private:
    vector<int> preVec;
    struct MySort {
        bool operator() (const vector<int> a, const vector<int> b) const 
        {
            return (a[2] < b[2]);
        }
    } myObject;
    
    void Init(int N)
    {
        for (int i = 0; i <= N; ++i) {
            preVec.push_back(i);
        }
    }
    
    vector<vector<int>> HelpSort(vector<vector<int>> connections)
    {
        sort(connections.begin(), connections.end(), myObject);
        return connections;
    }
    
    int FindRoot(int num)
    {
        while(preVec[num] != num) {
            num = preVec[num];
        }
        return num;
    }
    
    void Merge(int a, int b)
    {
        int root1 = FindRoot(a);
        int root2 = FindRoot(b);
        if (root1 < root2) {
            preVec[root2] = root1;
        } else if (root2 < root1) {
            preVec[root1] = root2;
        }
        return;
    }
    
    bool ExistWay(int N)
    {
        int headNum = 0;
        for (int i = 1; i <= N; ++i) {
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