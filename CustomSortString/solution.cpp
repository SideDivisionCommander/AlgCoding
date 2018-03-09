class Solution {
public:
    string customSortString(string S, string T) {
        map<char, int> indexDict;
        for(int i = 0; i < S.length(); ++i){
            indexDict.insert( pair<char, int>(S[i], i));
        }
        for(int i = 0; i < T.length(); ++i){
            int j = i;
            if (!indexDict.count(T[j])) continue;
            while(0 != j && ((indexDict.count(T[j-1]) && indexDict[T[j]] < indexDict[T[j-1]]) || !indexDict.count(T[j-1]))) {
                char temp = T[j-1];
                T[j-1] = T[j];
                T[j] = temp;
                --j;
            }
        }
        return T;
    }
};