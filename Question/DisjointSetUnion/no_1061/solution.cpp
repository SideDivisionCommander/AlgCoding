class Solution {
public:
    string smallestEquivalentString(string A, string B, string S)
    {
        if (A.size() <= 0) {
            return S;
        }
        Init(A, B, S);
        Union(A, B);
        return Process(S);
    }
private:
    unordered_map<char, char> preMap;
    
    void Init(const string& A, const string& B, const string& S)
    {
        for (int i = 0; i < A.size(); ++i) {
            preMap.emplace(pair<char, char>(A[i], A[i]));
            preMap.emplace(pair<char, char>(B[i], B[i]));
            preMap.emplace(pair<char, char>(S[i], S[i]));
        }
        return;
    }
    
    char FindRoot(char c)
    {
        while(preMap[c] != c) {
            c = preMap[c];
        }
        return c;
    }
    
    void Union(const string& A, const string& B)
    {
        for (int i = 0; i < A.size(); ++i) {
            char root1 = FindRoot(A[i]);
            char root2 = FindRoot(B[i]);
            if (root1 < root2) {
                preMap[root2] = root1;
            } else if (root2 < root1) {
                preMap[root1] = root2;
            }
        }
        return;
    }
    
    string Process(string s)
    {
        string resStr;
        for(auto c : s) {
            resStr.append(1, FindRoot(c));
        }
        return resStr;
    }
};