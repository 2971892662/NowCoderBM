//BM70 兑换零钱
#include <vector>
#include <algorithm>
using namespace std;
int minMoney(vector<int>& arr, int aim) {
	if (arr.size() == 0) {
		return -1;
	}
	sort(arr.begin(),arr.end());	//sort()函数在algorithm中
	vector<int> num(aim + 1, aim+1);
	num[0] = 0;
	for (int i = 1; i <= aim; i++) {
		for (int j = 0; j < arr.size(); j++) {
			if (i - arr[j] < 0) {
				continue;
			}
			num[i] = num[i] > num[i - arr[j]] + 1 ? num[i - arr[j]] + 1 : num[i];	//状态转移方程，这种迭代方程学习一下
		}
	}
	if (num[aim] == aim + 1) {
		return -1;
	}
	else {
		return num[aim];
	}
}
/*递归与迭代：
所有的递归算法都可以改写成迭代形式
*/