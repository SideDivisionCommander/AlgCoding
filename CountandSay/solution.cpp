class Solution {
public:
    /*
    template <typename T>
    string NumberToString(T Number){
        std::ostringstream ss;
        ss.clear();
        ss << Number;
        return ss.str();
    }
    */
    string countAndSay(int n) {
        string rstStr = "1";
        if(1 == n){
            return rstStr;
        }
        for(int i = 1; i < n; ++i){
            int duplicate = 0;
            string tmpStr;
            tmpStr.clear();
            for(int j = 0; j < rstStr.length(); ++j){
                duplicate++;
                if(j == rstStr.length()-1 || rstStr[j] != rstStr[j+1]){
                    //tmpStr.append(NumberToString(duplicate));
                    tmpStr += to_string(duplicate);
                    tmpStr += rstStr[j];
                    duplicate = 0;
                }
            }
            rstStr = tmpStr;
        }
        return rstStr;
    }
};