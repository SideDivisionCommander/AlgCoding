class Solution {
public:
    int min(int v1, int v2){
        return ( (v1 < v2) ? v1:v2 );
    }
    
    int minCostClimbingStairs(vector<int>& cost) {
        int f1 = 0, f2 = 0;
        for(int i = cost.size() - 1; i >= 0; --i ){
            int f0 = cost[i] + min(f1, f2);
            f2 = f1;
            f1 = f0;
        }
        return min(f1, f2);
    }
    
};