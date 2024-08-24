/*
C++中stack的常用操作：
stack<int> q;	//以int型为例
int x;
q.push(x);		//将x压入栈顶
q.top();		//返回栈顶的元素
q.pop();		//删除栈顶的元素
q.size();		//返回栈中元素的个数
q.empty();		//检查栈是否为空,若为空返回true,否则返回false
*/
#include <stack>
using namespace std;
class Solution
{
public:
    void push(int node) {
        stack1.push(node);
    }

    int pop() {
        if (stack2.empty()) {   //要加上这一if判断，只有当stack2空的时候才转移
            while (!stack1.empty()) {
                stack2.push(stack1.top());
                stack1.pop();
            }
        }
        int res = stack2.top();
        stack2.pop();
        return res;
    }

private:
    stack<int> stack1;
    stack<int> stack2;
};
//总结：在草纸上模拟一遍算法就能出来个大概