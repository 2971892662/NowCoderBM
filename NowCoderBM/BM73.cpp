
//BM73 最长回文子串
#include <string>
#include <vector>
using namespace std;

int getLongestPalindrome(string A) {
	/*中心扩展法
	时间复杂度O(n^2),空间复杂度O(1)
	如果采用暴力解法，时间复杂度为O(n^3)
	*/
	int max = 0;
	int temp = A.size();
	for (int i = 0; i <= 2 * temp; i = i + 2) {
		A.insert(A.begin() + i, '*');
	}
	int i = 0;
	int j = 0;
	int count = 0;
	for (int m = 0; m < A.size(); m++) {
		if (A[m] == '*') {
			count = 0;
		}
		else {
			count = 1;
		}
		i = m - 1;
		j = m + 1;
		while (i >= 0 && j < A.size()) {
			if (count > max) {
				max = count;
			}
			if (A[i] == A[j]) {
				if (A[i] != '*') {
					count = count + 2;
					if (count > max) {
						max = count;
					}
				}
				i--;
				j++;
			}
			else {
				break;
			}
		}
	}
	return max;
	//进阶：Manachar算法
}
