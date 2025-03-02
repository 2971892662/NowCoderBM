//BM61 矩阵最长递增路径
#include <iostream>
#include <vector>

using namespace std;

void findPath(vector<vector<int>>& matrix, int len, int& record, int i, int j, int x, int y) {
    if (i < 0 || i >= matrix.size() || j < 0 || j >= matrix[0].size()) {
        return;
    }
    if (matrix[i][j] > matrix[x][y]) { //不能加等号，可能导致无限循环
        if (len + 1 > record) {
            record = len+1;
        }
        findPath(matrix, len + 1, record, i + 1, j, i, j);
        findPath(matrix, len + 1, record, i - 1, j, i, j);
        findPath(matrix, len + 1, record, i, j + 1, i, j);
        findPath(matrix, len + 1, record, i, j - 1, i, j);
    }
}

void findLongestPath(vector<vector<int>>& matrix, int len, int& record, int i, int j) {
    len = 1;
    findPath(matrix, len, record, i + 1, j, i, j);
    findPath(matrix, len, record, i - 1, j, i, j);
    findPath(matrix, len, record, i, j + 1, i, j);
    findPath(matrix, len, record, i, j - 1, i, j);
}

int solve(vector<vector<int> >& matrix) {
    int record = 0; //记录当前最长路径
    for (int i = 0; i < matrix.size(); i++) {
        for (int j = 0; j < matrix[0].size(); j++) {
            findLongestPath(matrix, 0, record, i, j);
        }
    }
    return record;
}