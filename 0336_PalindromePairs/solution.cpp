class Solution {
public:
    /*
    //[Performance]
    //exceed max time limit for some testcase, but it should be a correct solution functionally.
    //[Algorithm]
    //To iter all the words[i] + words[j] possibility, check whether every trail is palindrome or not.  
    vector<vector<int>> palindromePairs(vector<string>& words) {
        vector<vector<int> > resultVec;
        resultVec.clear();
        for(int i = 0 ; i < words.size(); ++i){
            for(int j = 0; j < words.size(); ++j){
                if(i == j) continue;
                if(palindrome(words[i]+words[j])){
                    vector<int> vec;
                    vec.clear();
                    vec.push_back(i);
                    vec.push_back(j);
                    resultVec.push_back(vec);
                } 
            }
        }
        return resultVec;
    }
    bool palindrome(string str){
         int i = 0;
         int j = str.size() - 1; 

         while(i < j) {
             if(str[i++] != str[j--]) return false;
         }

         return true;
    }
    */

    //[Performance]
    //Cost 323ms for 134 testcases, beat 15%, not good
    //[Algorithm]
    //Establish the map for all words and their own index.
    //Then supplementary every word with suffix or prefix,
    //check the palindrome and whether the suffix or prefix
    //is in map. 
    vector<vector<int>> palindromePairs(vector<string>& words) {
        vector<vector<int> > resultVec;
        resultVec.clear();
        unordered_map<string, int> dict;
        for(int i = 0; i < words.size(); i++) {
            dict[words[i]] = i;
        }
        for(int i = 0 ; i < words.size(); ++i){
            for(int j = 0; j <= words[i].length(); ++j){
                string suffix = words[i].substr(0, j);
                reverse(suffix.begin(), suffix.end());
                if(isPalindrome(words[i] + suffix)){
                    if(dict.find(suffix) != dict.end() && i != dict[suffix]) {
                        resultVec.push_back({i, dict[suffix]});
                    }
                }
                string prefix = words[i].substr(words[i].length()-j, j);
                reverse(prefix.begin(), prefix.end());
                if(isPalindrome(prefix + words[i])){
                    if(dict.find(prefix) != dict.end() && i != dict[prefix] && prefix.length() != words[i].length()) { // prefix.length() != words[i].length(), avoid duplicate
                        resultVec.push_back({dict[prefix], i});
                    }
                }
            }
        }
        return resultVec;
    }

private:
    bool isPalindrome(string str){
         int i = 0;
         int j = str.size() - 1; 

         while(i < j) {
             if(str[i++] != str[j--]) return false;
         }

         return true;
    }

};