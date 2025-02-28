//BM84 最长公共前缀
#include <string>
#include <vector>
using namespace std;
string longestCommonPrefix(vector<string>& strs){
    if (strs.size() == 0) {
        return "";
    }
    auto it = strs.begin();
    string temp;
    for (unsigned int i = 0; i < (strs.front().length()); i++) {    //size_t应该是无符号类型，所以把int也改成无符号数
        string base = string(strs.front(), 0, i + 1);
        while (it != strs.end()) {
            if ((*it).length() < (i + 1)) {
                return string(*it, 0, i);
            }
            temp = string(*it, 0, i + 1);
            if (temp != base) {
                return string(temp, 0, i);
            }
            it++;   //使用迭代器
        }
        it = strs.begin();
    }
    return strs.front();
}