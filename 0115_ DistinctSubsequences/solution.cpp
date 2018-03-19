class Solution {
public:
    /*
    //[Performance]
    //exceed max time limit for some testcase, but it should be a correct solution functionally.
    //[Algorithm]
    //To Get all the erasing char position which make the length of string "s" equals the
    //the length of string "t".
    //And then see whether the every trial equal string "t" or not.   
    int numDistinct(string s, string t) {
        vector<int> selectors;
        int result = 0;
        selectors.clear();
        if(s.length() < t.length()) return 0;
        if(s.length() == t.length()){
            if(0 == s.compare(t)){
                return 1;
            }
            else{
                return 0;
            }
        }
        for(int i = 0; i < t.length(); ++i){
            selectors.push_back(1);
        }
        for(int i = 0; i < s.length() - t.length(); ++i){
            selectors.push_back(0);
        }
        do{
            string str;
            str.clear();
            for(int i = 0; i < s.length(); ++i){
                if(selectors[i]){
                    str.append(1, s[i]);
                }
            }
            if(0 == str.compare(t)) result++;
        }while(prev_permutation(selectors.begin(), selectors.end()));
        return result;
    }
    */
    //[Performance]
    //Cost 6ms for 63 testcases, beat 85%, great.
    //[Algorithm]
    //Using DP. s[1..j] express string s, t[1..i] express string t
    //dp[i][j] means distinct substring num.
    int numDistinct(string s, string t) {
        int lengthOfS = s.length();
        int lengthOfT = t.length();
        vector<vector<int> > dp(lengthOfT+1, vector<int>(lengthOfS+1));
        for(int j = 0; j <= lengthOfS; ++j){
            dp[0][j] = 1;
        }
        for(int i = 1; i <= lengthOfT; ++i){
            dp[i][0] = 0;
        }
        for(int i = 1; i <= lengthOfT; ++i){
            for(int j = 1; j <= lengthOfS; ++j){
                if(t[i-1] != s[j-1]) dp[i][j] = dp[i][j-1];
                else dp[i][j] = dp[i][j-1] + dp[i-1][j-1];
            }
        }
        return dp[lengthOfT][lengthOfS];
    }
};