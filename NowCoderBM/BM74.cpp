//BM74 数字字符串转化成IP地址
#include <string>
#include <vector>
#include <stdlib.h>

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
        vector<string> res = { "" };
        return res;
    }
}