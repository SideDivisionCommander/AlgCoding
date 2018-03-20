class Solution {
public:
    //[Performance]
    //Cost 7ms for 294 testcases.
    //[Algorithm]
    //omit   
    string addBinary(string a, string b) {
        int lengthOfA = a.length();
        int lengthOfB = b.length();
        string str1, str2, str3;
        if(lengthOfA <= lengthOfB){
            str1 = a;
            str2 = b.substr(lengthOfB-lengthOfA ,lengthOfA);
            str3 = b.substr(0, lengthOfB-lengthOfA);
        }
        else{
            str1 = b;
            str2 = a.substr(lengthOfA-lengthOfB ,lengthOfB);
            str3 = a.substr(0, lengthOfA-lengthOfB);
        }
        char overBit = '0';
        string result;
        result.clear();
        for(int i = str1.length()-1; i >= 0; --i){
            if(str1[i] == '1' && str2[i] == '1'){
                if(overBit == '0'){
                    result.insert(0, 1, '0');
                    overBit = '1';
                } 
                else{
                    result.insert(0, 1, '1');
                    overBit = '1';
                } 
            }
            else if(str1[i] == '0' && str2[i] == '0'){
                if(overBit == '0'){
                    result.insert(0, 1, '0');
                    overBit = '0';
                } 
                else{
                    result.insert(0, 1, '1');
                    overBit = '0';
                } 
            }
            else{
                if(overBit == '0'){
                    result.insert(0, 1, '1');
                    overBit = '0';
                } 
                else{
                    result.insert(0, 1, '0');
                    overBit = '1';
                } 
            }
        }
        for(int i = str3.length()-1; i >= 0; --i){
            if(str3[i] == '0'){
                if(overBit == '0'){
                    result.insert(0, 1, '0');
                    overBit = '0';
                }
                else{
                    result.insert(0, 1, '1');
                    overBit = '0';
                } 
            }
            else{
                if(overBit == '0'){
                    result.insert(0, 1, '1');
                    overBit = '0';
                }
                else{
                    result.insert(0, 1, '0');
                    overBit = '1';
                } 
            }
        }
        if(overBit == '1') result.insert(0, 1, '1');
        if (result.empty()) return "0";
        return result;
    }
};