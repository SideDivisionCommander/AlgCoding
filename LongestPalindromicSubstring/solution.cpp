class Solution {
public:
    string longestPalindrome(string s) {
        int longest = 0;
        string result, resultB;
        result.clear();
        resultB.clear();
        for(int i = 0; i < s.length(); ++i){
            for(int j = 0; j <= i; ++j){
                if(s[i-j] != s[i+j]){
                    if(j-1 > longest){
                        longest = j-1;
                        result = s.substr(i-longest, longest*2+1);
                    }
                    break;
                }
                if( 0 == i-j || s.length()-1 == i+j){
                    if(j >= longest){
                        longest = j;
                        result = s.substr(i-longest, longest*2+1);
                    }
                    break;
                }
            }
            if(s.length()-i-1 <= longest){
                break;
            }
        }
        
        longest = 0;
        for(int i = 0; i < s.length(); ++i){
            for(int j = 0; j <= i; ++j){
                if(s[i-j] != s[i+1+j]){
                    if(j > longest){
                        longest = j;
                        resultB = s.substr(i-longest+1, longest*2);
                    }
                    break;
                }
                if(0 == i-j || s.length()-1 == i+1+j){
                    if(j >= longest){
                        longest = j;
                        resultB = s.substr(i-longest, (longest+1)*2);
                    }
                    break;
                }
            }
            if(s.length()-i-1 <= longest){
                break;
            }
        }
        return result.length() > resultB.length() ? result:resultB;
    }
};