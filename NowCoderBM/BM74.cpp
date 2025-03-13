//BM74 数字字符串转化成IP地址
#include <string>
#include <vector>
#include <stdlib.h>
#include <regex>

using namespace std;

/*
void select(string str,int num,int last,vector<string> finalres) {
    
    num:还能插几个点
    last:上一个点的位置
    //之前做的对不对
    string temp = "";
    temp.copy(str, str.length() - last - 1, last + 1);
    if(num==0&&atoi())
    for (int i = last + 1; i <= str.size(); i++) {
        str.insert(str.begin() + i, '.');
        select(str, num - 1, i, finalres);
        str.erase(str.begin() + i);
    }
}
失败总结:参数太多，导致太复杂了，不如一次完成所有'.'的插入
*/

vector<string> restoreIpAddresses(string s) {
    if (s.length() < 4) {
        vector<string> res;
        return res;
    }
    string a = "";
    string b = "";
    string c = "";
    string d = "";
    regex IP("0[0-9]|0[0-9][0-9]");
    vector<string> res;
    for (int i = 0; i < s.size(); i++) {
        for (int j = i + 1; j < s.size(); j++) {
            for (int k = j + 1; k < s.size()-1; k++) {
                a = s.substr(0, i+1);
                b = s.substr(i+1, j - i);
                c = s.substr(j+1, k - j);
                d = s.substr(k+1, s.size() - k-1);
                //排除前导0
                if (regex_match(a, IP) || regex_match(b, IP) || regex_match(c, IP) || regex_match(d, IP)) {
                    continue;
                }
                if (atoi(a.c_str()) <= 255 && atoi(b.c_str()) <= 255 && atoi(c.c_str()) <= 255 && atoi(d.c_str()) <= 255) {
                    res.push_back(a + "." + b + "." + c + "." + d);
                }
            }
        }
    }
    return res;
}