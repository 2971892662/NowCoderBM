//BM43包含MIN函数的栈
#define MaxSize 350
//定义一个顺序栈
//借助一个辅助数组来在O(1)时间复杂度内获取栈中最小元素
struct myStack {
    int val[MaxSize];
    int top = -1;
    int minVal[MaxSize];
};
class Solution {
public:
    myStack s;
    void push(int value) {
        if (s.top == MaxSize - 1) {
            return;
        }
        if (s.top == -1) {
            s.top++;
            s.val[s.top] = value;
            s.minVal[s.top] = value;
        }
        else {
            s.top++;
            s.val[s.top] = value;
            if (value < s.minVal[s.top - 1]) {
                s.minVal[s.top] = value;
            }
            else {
                s.minVal[s.top] = s.minVal[s.top - 1];
            }
        }
    }
    void pop() {
        if (s.top == -1) {
            return;
        }
        s.top--;
    }
    int top() {
        if (s.top == -1) {
            return -1;
        }
        return s.val[s.top];
    }
    int min() {
        return s.minVal[s.top];
    }
};