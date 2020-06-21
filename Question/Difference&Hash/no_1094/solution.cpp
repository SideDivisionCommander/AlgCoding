class Solution {
public:
    bool carPooling(vector<vector<int>>& trips, int capacity) {
        if (trips.size() <= 0) {
            return true;
        }
        Init();
        Process(trips);
        for (auto v : helpVec) {
            if (v > capacity) {
                return false;
            }
        }
        return true;
    }
private:
    vector<int> helpVec;
    static constexpr int MAX_TRIP = 1001;
    
    void Init()
    {
        helpVec.assign(MAX_TRIP, 0);
        return;
    }
    
    void Process(vector<vector<int>>& trips)
    {
        for (int i = 0; i < trips.size(); ++i) {
            for (int j = trips[i][1]; j < trips[i][2]; ++j) {
                helpVec[j] += trips[i][0];
            }
        }
        return;
    }
};