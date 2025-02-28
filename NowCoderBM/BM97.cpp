//BM97 旋转数组
#include <vector>
using namespace std;
inline void swap97(vector<int>& a, int m, int n) {
    int temp = a[m];
    a[m] = a[n];
    a[n] = temp;
}
inline void reverse97(vector<int>& a, int start, int end) {
    while (start < end) {
        swap97(a, start, end);
        start++;
        end--;
    }
}
vector<int> solve97(int n, int m, vector<int>& a) { //两次翻转问题
    m = m % n;
    reverse97(a, 0, n-m - 1);   
    reverse97(a, n-m, n - 1);
    reverse97(a, 0, n - 1);
    return a;
    /*调整参数也可实现左移
    reverse97(a,0,m-1);
    reverse97(a,m,n-1);
    reverse97(a,0,n-1);
    */
}