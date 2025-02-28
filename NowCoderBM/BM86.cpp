//BM86 大数加法
#include <string>
using namespace std;
string solve86(string s, string t) {
    if (s == "") {
        return t;
    }
    if (t == "") {
        return s;
    }
    string m = "";
    if (s.length() > t.length()) {  //s更长
    }
    else {
        m = t;
        t = s;
        s = m;
    }
    int carry = 0;
    int temp = 0;
    int i = s.length() - 1;
    int j = t.length() - 1;
    for (; j >= 0; i--,j--) {   //利用ASCII码差值
        temp = (s[i]-'0'+t[j]-'0'+carry)/10;
        s[i] = (s[i] - '0' + t[j] - '0' + carry) % 10 + '0';
        carry = temp;
    }
    for (; i >= 0; i--) {
        temp = (s[i] - '0' +  carry) / 10;
        s[i] = (s[i] - '0' +  carry) % 10 + '0';
        carry = temp;
    }
    if (carry != 0) {
        char m = carry + '0';
        string n;
        n = m;  //不能string n=m;因为这不是构造函数
        return n + s;
    }
    else {
        return s;
    }
}