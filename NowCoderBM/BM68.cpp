//BM68 矩阵的最小路径和
#include <vector>
using namespace std;
int minPathSum(vector<vector<int> >& matrix) {
    if (matrix.size() == 0 || matrix[0].size() == 0) {
        return 0;
    }
    for (int i = matrix.size() - 1; i >= 0; i--) {
        for (int j = matrix[0].size() - 1; j >= 0; j--) {
            if (i == matrix.size()-1 || j == matrix[0].size()-1) {
                if (i == matrix.size()-1 && j == matrix[0].size()-1) {
                    matrix[i][j] = matrix[i][j];
                }
                else if (i == matrix.size() - 1) {
                    matrix[i][j] = matrix[i][j + 1] + matrix[i][j];
                }
                else {
                    matrix[i][j] = matrix[i + 1][j] + matrix[i][j];
                }
            }
            else {
                matrix[i][j] = (matrix[i][j + 1] < matrix[i + 1][j] ? matrix[i][j + 1] : matrix[i + 1][j])+matrix[i][j];
            }
        }
    }
    return matrix[0][0];
}
