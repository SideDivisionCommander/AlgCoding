/*
 用单调递减栈   
*/
class StockSpanner {
public:
    StockSpanner() {
        index = 0;
        helpStack.push(index);
        helpVec.push_back(INT_MAX);
    }
    
    int next(int price) {
        index++;
        helpVec.push_back(price);
        while (!helpStack.empty() && helpVec[helpStack.top()] <= price) {
            helpStack.pop();
        }
        int res = index - helpStack.top();
        helpStack.push(index);
        return res;
    }
private:
    stack<int> helpStack;
    int index;
    vector<int> helpVec;
};

/**
 * Your StockSpanner object will be instantiated and called as such:
 * StockSpanner* obj = new StockSpanner();
 * int param_1 = obj->next(price);
 */