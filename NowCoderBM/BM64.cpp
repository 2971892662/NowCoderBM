//BM64 最小花费爬楼梯

#include <vector>

using namespace std;

int minVal(int i, int j) {
    if (i <= j) {
        return i;
    }
    else {
        return j;
    }
}

int minCostClimbingStairs(vector<int>& cost) {
    if (cost.size() == 0) {
        return 0;
    }
    if (cost.size() == 1 || cost.size() == 2) {
        return cost[0];
    }
    vector<int> mincost(cost.size(), 0);
    mincost[mincost.size() - 1] = cost[mincost.size() - 1];
    mincost[mincost.size() - 2] = cost[mincost.size() - 2];
    for (int j = mincost.size() - 3; j >= 0; j--) {
        mincost[j] = cost[j] + minVal(mincost[j + 1], mincost[j + 2]);
    }
    return minVal(mincost[0], mincost[1]);
}