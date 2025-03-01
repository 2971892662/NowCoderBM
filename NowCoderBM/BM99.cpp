//BM99 顺时针旋转矩阵
#include <vector>
using namespace std;
vector<vector<int> > rotateMatrix99(vector<vector<int> >& mat, int n) {
    vector<vector<int>> res(n, vector<int>(n, 0)); 
    //vector与二维数组
    //使用默认构造函数，然后res[0].pushback()是不行的，因为res[0]不存在。
    for (int i = 0; i < n; i++) {
        int j = n - 1;
        int k = 0;
        for (; j >= 0; ) {
            res[i][k] = mat[j][i];
            j--;
            k++;
        }
    }
    return res;
}

//空间复杂度为O(1)的方法：先转置矩阵，然后每行内交换
vector<vector<int> > rotateMatrix99v2(vector<vector<int> >& mat, int n) {
    //上三角交换实现矩阵转置，都交换等于没交换
    int temp = 0;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j <= i; j++) {
            temp = mat[i][j];
            mat[i][j] = mat[j][i];
            mat[j][i] = temp;
        }
    }
    for (int i = 0; i < n; i++) {
        reverse(mat[i].begin(), mat[i].end());
    }
    return mat;
}