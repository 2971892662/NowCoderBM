//BM44 有效括号序列
//括号匹配问题
//给出一个仅包含字符'(',')','{','}','['和']',的字符串，判断给出的字符串是否是合法的括号序列
#include <string>
#define MaxSize 10005
using namespace std;
struct mystack {
    char val[MaxSize];
    int top;
};
void initStack(mystack& s) {
    s.top = -1;
}
bool push(mystack& s, char val) {
    if (s.top == MaxSize - 1) {
        return false;
    }
    s.top++;
    s.val[s.top] = val;
    return true;
}
bool pop(mystack& s, char& val) {
    if (s.top == -1) {
        return false;
    }
    val = s.val[s.top];
    s.top--;
    return true;
}
bool getTop(mystack& s, char& val) {
    if (s.top == -1) {
        return false;
    }
    val = s.val[s.top];
    return true;
}
bool isEmpty(mystack& s) {
    if (s.top == -1) {
        return true;
    }
    else {
        return false;
    }
}
bool isValid(string s) {
    int i = 0;
    mystack st;
    initStack(st);
    char t;
    while (s[i] != '\0') {
        if (s[i] == '{' || s[i] == '[' || s[i] == '(') {
            push(st, s[i]);
            i++;
            continue;
        }
        switch (s[i]) {
        case '}':
            if (isEmpty(st)) {
                return false;
            }
            pop(st, t);
            if (t != '{') {
                return false;
            }
            i++;
            break;
        case ']':
            if (isEmpty(st)) {
                 return false;
            }
            pop(st, t);
            if (t != '[') {
                return false;
            }
            i++;
            break;
        case ')':
            if (isEmpty(st)) {
                return false;
            }
            pop(st, t);
            if (t != '(') {
                return false;
            }
            i++;
            break;
        }
    }
    return isEmpty(st);
}