class Solution {
public:
    int minMeetingRooms(vector<vector<int>>& intervals)
    {
        if (intervals.size() <= 0) {
            return 0;
        }
        Init(intervals);
        for (int i = 1; i <= end; ++i) {
            helpVec[i] += helpVec[i - 1]; 
        }
        return Process();
    }
private:
    vector<int> helpVec;
    static constexpr int MAX_SIZE = 1000000;
    int end; 
    void Init(vector<vector<int>>& intervals)
    {
        helpVec.assign(MAX_SIZE, 0);
        end = 0;
        for (auto v : intervals) {
            helpVec[v[0]]++;
            helpVec[v[1]]--;
            end = max(v[1], end);
        }
        return;
    }
    
    int Process()
    {
        int rooms = 0;
        for (auto i : helpVec) {
            rooms = max(rooms, i);
        }
        return rooms;
    }
};