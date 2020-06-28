char * multiply(char * num1, char * num2){
    if (strlen(num1) == 1 && num1[0] == '0') {
        printf("0\n");
        return "0";
    }
    if (strlen(num2) == 1 && num2[0] == '0') {
        printf("0\n");
        return "0";
    }
    static char result[300];
    memset(result, 0, sizeof(result));
    int maxLen = strlen(num1) + strlen(num2) - 2;
    for (int i = strlen(num2) - 1; i >= 0; --i) {
        int cache = 0;
        int resultCache = 0;
        for (int j = strlen(num1) - 1; j >=0; --j) {
            int r = (num2[i] - '0') * (num1[j] - '0');
            int g = (r + cache)%10;
            cache = (r + cache)/10;
            int position = strlen(num1) + strlen(num2) - (j + 1) - (i + 1);
            int rg = (g + result[position] + resultCache)%10;
            resultCache = (g + result[position] + resultCache)/10;
            result[position] = rg;
            if (j == 0) {
                if (resultCache + cache > 0) {
                    result[position + 1] += (resultCache + cache);
                    if (i == 0) {
                        maxLen++;
                    }
                }
            }
        }
    }
    for (int i = 0; i < (strlen(num1) + strlen(num2))/2; ++i) {
        
        char tmp = result[i];
        result[i] = result[maxLen - i];
        result[maxLen - i] = tmp;
    }
    for (int i = 0; i <= maxLen; ++i) {
        result[i] += '0';
    }
    // printf("%s\n", result);
    return result;
}