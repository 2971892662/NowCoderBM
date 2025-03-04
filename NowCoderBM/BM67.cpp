//BM67 不同路径的数目
#include <vector>
using namespace std;

int uniquePaths(int m, int n) {
    vector<vector<int>> num(m, vector<int>(n, 0));
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            if (i == 0 || j == 0) {
                num[i][j] = 1;
            }
            else {
                num[i][j] = num[i - 1][j] + num[i][j - 1];
            }
        }
    }
    return num[m-1][n-1];
}