//BM71 最长上升子序列
#include <vector>
using namespace std;
int LIS(vector<int>& arr) {
	if (arr.size() == 0) {
		return 0;
	}
	int lis = 1;
	vector<int> len(arr.size(), 1);
	for (int i = 0; i < arr.size(); i++) {
		for (int j = 0; j < i; j++) {
			if (arr[j] < arr[i]) {
				len[i] = len[i] < len[j] + 1 ? len[j] + 1 : len[i];
				if (len[i] > lis) {
					lis = len[i];
				}
			}
		}
	}
	return lis;
}