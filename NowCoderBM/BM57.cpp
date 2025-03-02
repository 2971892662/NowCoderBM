//BM57 岛屿数量
#include <vector>
using namespace std;

//广度优先是非递归的（借助队列），深度优先是递归的
void DFS(vector<vector<char> > grid, vector<vector<bool>> &visited,int i,int j) {
    if (i < 0 || i >= grid.size() || j < 0 || j >= grid[0].size()) {
        return;
    }
    if (grid[i][j] == '1'&&visited[i][j]==false) {
        visited[i][j] = true;
        DFS(grid, visited, i - 1, j);
        DFS(grid, visited, i + 1, j);
        DFS(grid, visited, i , j-1);
        DFS(grid, visited, i , j+1);
    }
}
/*问题分析：内存超过使用限制
理论：每次递归调用都会在栈上分配一定的内存（存储局部变量、返回地址等）。如果递归深度过大，栈空间可能会耗尽，导致内存超限。
*/
int solve57(vector<vector<char> >& grid) {
    vector<vector<bool>> visited(grid.size(), vector<bool>(grid[0].size(), false));    //二维vector初始化
    int count = 0;
    for (int i = 0; i < grid.size(); i++) {
        for (int j = 0; j < grid[0].size(); j++) {
            if (grid[i][j] == '1' && visited[i][j] == false) {
                DFS(grid, visited, i, j);
                count++;
            }
        }
    }
    return count;
}
