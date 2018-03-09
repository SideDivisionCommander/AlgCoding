class Solution {
public:
    int minDistance(string word1, string word2) {
        int len1 = word1.length();
        int len2 = word2.length();
        //dp[i][j] means min distance between word1[1]-word[i] and word2[1]-word2[j]
        vector<vector<int> > dp(len1+1, vector<int>(len2+1));        
        for(int i = 0; i < len1+1; ++i){
            dp[i][0] = i;
        }
        for(int j = 0; j < len2+1; ++j){
            dp[0][j] = j;
        }
        
        for(int i = 1; i <= len1; ++i){
            for(int j = 1; j <= len2; ++j){
                if( word1[i-1] == word2[j-1] ){
                    dp[i][j] = dp[i-1][j-1];
                    continue;
                } 
                dp[i][j] = min(dp[i-1][j]+1, dp[i][j-1]+1, dp[i-1][j-1]+1);
            }
        }
        return dp[len1][len2];
    }
    
    int min(int v1, int v2, int v3){
        return ( (((v1 < v2) ? v1:v2) < v3) ?  ((v1 < v2) ? v1:v2):v3 );
        //return (v1 > v2?(v2 > v3 ? v3 :v2):(v1 > v3? v3:v1));
    }
};