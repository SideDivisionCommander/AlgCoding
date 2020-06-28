class Solution {
public:
    int findMinArrowShots(vector<vector<int>>& points)
    {
        if (points.size() == 0) {
            return 0;
        }
        Init(points);
        int currEnd = sortedPoints[0][1];
        res = 1;
        for (int i = 1; i < sortedPoints.size(); ++i) {
            if (sortedPoints[i][0] > currEnd) {
                res++;
                currEnd = sortedPoints[i][1];
            }
        }
        return res;
        
    }
private:
    vector<vector<int>> sortedPoints;
    int res;
    
    static bool HelpSort(vector<int> vec1, vector<int> vec2)
    {
        return (vec1[1] < vec2[1]);
    }
    
    void Init(vector<vector<int>>& points)
    {
        sortedPoints = points;
        sort(sortedPoints.begin(), sortedPoints.end(), HelpSort);
        res = 0;
        return;
    }
};