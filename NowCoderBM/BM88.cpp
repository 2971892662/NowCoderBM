//BM88 �ж��Ƿ��ǻ����ַ���
#include <iostream>
#include <string.h>
using namespace std;
bool judge(string str) {
    int j = str.length() - 1;
    int i = 0;
    while (str[i] - str[j] == 0 && i < str.length()) {  //Ҫ��ֹԽ�磬��Ȼ����򱨴�
        i++; j--;
    }
    if (i == str.length()) {
        return true;
    }
    else {
        return false;
    }
}
