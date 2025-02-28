//BM85 验证IP地址
#include <string>
#include <regex>
using namespace std;
string solve(string IP) {
	//使用正则表达式
	regex v4("(([1-9]|[1-9][0-9]|1[1-9][1-9]|2[0-4][0-9]|25[0-5])\\.){3}([1-9]|[1-9][0-9]|1[1-9][1-9]|2[0-4][0-9]|25[0-5])");
	regex v6("((([0-9a-fA-F]){1,4})\\:){7}([0-9a-fA-F]){4}");
	bool IP4 = regex_match(IP, v4);
	bool IP6 = regex_match(IP, v6);
	if (IP4 == true) {
		return "IPv4";
	}
	if (IP6 == true) {
		return "IPv6";
	}
	return "Neither";
}