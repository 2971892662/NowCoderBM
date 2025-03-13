//BM75 编辑距离
#include <string>
#include <vector>
using namespace std;

//采用递归时间复杂大会非常高，O(3^n)级别，对于长字符串非常费时
void dis(string str1, string str2, int i, int& len) {  //str1短，str2长
    if (i == str2.length() && i < str1.length()) {  //虽然str1短，但对str1不断插入有可能让其比str2长
        len = len + (str1.length() - str2.length());
        return;
    }
    if (i >= str1.length() && i <= str2.length()) {
        len = len + (str2.length() - str1.length());
        return;
    }
    if (str1[i] == str2[i]) {
        dis(str1, str2, i + 1, len);
        return;
    }
    int lena = len;
    int lenb = len;
    int lenc = len;
    //1.插入
    str1.insert(str1.begin() + i, str2[i]);
    lena++;
    dis(str1, str2, i + 1, lena);
    str1.erase(str1.begin() + i);
    //2.删除
    char temp = str1[i];
    str1.erase(str1.begin() + i);
    lenb++;
    dis(str1, str2, i, lenb);
    str1.insert(str1.begin() + i, temp);
    //3.修改
    str1[i] = str2[i];
    lenc++;
    dis(str1, str2, i + 1, lenc);
    str1[i] = temp;

    if (lena <= lenb && lena <= lenc) {
        len = lena;
    }
    if (lenb <= lena && lenb <= lenc) {
        len = lenb;
    }
    if (lenc <= lena && lenc <= lenb) {
        len = lenc;
    }
}

int editDistance(string str1, string str2) {
    vector<vector<int>> arr(str1.length() + 1, vector<int>(str2.length() + 1, 0));
    for (int i = 0; i < str1.length() + 1; i++) {
        arr[i][0] = i;
    }
    for (int i = 0; i < str2.length() + 1; i++) {
        arr[0][i] = i;
    }
    for (int i = 1; i < str1.length() + 1; i++) {
        for (int j = 1; j < str2.length() + 1; j++) {
            if (str1[i - 1] == str2[j - 1]) {
                arr[i][j] = arr[i - 1][j - 1];
                continue;
            }
            int a = arr[i - 1][j];
            int b = arr[i - 1][j - 1];
            int c = arr[i][j - 1];
            if (a <= b && a <= c) { //使用<=，这样在具有相同值时能做出正确选择
                arr[i][j] = a + 1;
            }
            else if (b <= a && b <= c) {
                arr[i][j] = b + 1;
            }
            else {
                arr[i][j] = c + 1;
            }
        }
    }
    return arr[str1.length()][str2.length()];
}