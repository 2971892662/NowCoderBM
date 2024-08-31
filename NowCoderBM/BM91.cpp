//BM91 ·´×ª×Ö·û´®
#include <string>
using namespace std;
string solve(string str) {
	string s(str.length(), '0');
	for (int j = str.length() - 1,i=0; j >= 0; j--,i++) {
		s[i] = str[j];
	}
	return s;
}