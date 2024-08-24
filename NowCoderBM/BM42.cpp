/*
C++��stack�ĳ��ò�����
stack<int> q;	//��int��Ϊ��
int x;
q.push(x);		//��xѹ��ջ��
q.top();		//����ջ����Ԫ��
q.pop();		//ɾ��ջ����Ԫ��
q.size();		//����ջ��Ԫ�صĸ���
q.empty();		//���ջ�Ƿ�Ϊ��,��Ϊ�շ���true,���򷵻�false
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
        if (stack2.empty()) {   //Ҫ������һif�жϣ�ֻ�е�stack2�յ�ʱ���ת��
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
//�ܽ᣺�ڲ�ֽ��ģ��һ���㷨���ܳ��������