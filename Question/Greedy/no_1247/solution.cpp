class Solution {
public:
    int minimumSwap(string s1, string s2)
    {
        if (s1.size() != s2.size()) {
            return -1;
        }
        if (s1.compare(s2) == 0) {
            return 0;
        }
        Init();
        for (int i = 0; i < s1.size(); ++i) {
            if (s1[i] != s2[i]) {
                if (s1[i] == 'x') {
                    xy++;
                } else {
                    yx++;
                }
            }
        }
        if ((xy + yx) % 2 != 0) {
            return -1;
        }
        int num1 = (xy / 2 + yx / 2);
        int num2 = (xy % 2 + yx % 2);
        return num1 + num2;
    }
private:
    int xy;
    int yx;
    
    void Init()
    {
        xy = 0;
        yx = 0;
        return;
    }
};