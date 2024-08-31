//BM88 判断是否是回文字符串
#include <iostream>
#include <string.h>
using namespace std;
bool judge(string str) {
    int j = str.length() - 1;
    int i = 0;
    while (str[i] - str[j] == 0 && i < str.length()) {  //要防止越界，不然会横错或报错
        i++; j--;
    }
    if (i == str.length()) {
        return true;
    }
    else {
        return false;
    }
}
