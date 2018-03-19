class Solution {
public:
    //[Performance]
    //31ms, beat 70%, so so.
    int lengthOfLongestSubstring(string s) {
        string result, tmpResult;
        result.clear();
        tmpResult.clear();
        for (int i = 0; i < s.length(); ++i){
            size_t found = tmpResult.find(s[i]);
            if(found != string::npos){
                if(tmpResult.length() > result.length()){
                    result = tmpResult;
                }
                tmpResult = tmpResult.erase(0, found+1);
            }
            tmpResult.append(1, s[i]);
        }
        if(tmpResult.length() > result.length()){
            result = tmpResult;
        }
        return result.length();
    }  
};