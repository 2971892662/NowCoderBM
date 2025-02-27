//BM83 字符串变形
#include <string>
using namespace std;
void swap(string &s, int low, int high, char temp) { //交换要使用引用，不然换不了
    temp = s[low];
    s[low] = s[high];
    s[high] = temp;
}
string trans(string s, int n) {
    //两次翻转
    int i = 0;
    int j = 0;
    int low = 0;
    int high = 0;
    char temp = 'a';
    for (; j < n;) {
        while (s[j] - ' ' != 0&&j<n) {  //二次判断防止死循环
            j++;
        }
        low = i;
        high = j - 1;
        while (low < high) {
            swap(s, low, high, temp);
            low++;
            high--;
        }
        i = j + 1;
        j = i;
    }
    i = 0;
    j = n - 1;
    while (i < j) {
        swap(s, i, j, temp);
        i++;
        j--;
    }
    for (i = 0; i < n; i++) {   //ASCII先大写后小写
        if (s[i] >= 'a' && s[i] <= 'z') {
            s[i] = s[i] - 32; // 小写转大写
        }
        else if (s[i] >= 'A' && s[i] <= 'Z') {
            s[i] = s[i] + 32; // 大写转小写
        }
    }
    return s;
}