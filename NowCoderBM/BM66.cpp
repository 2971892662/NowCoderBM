//BM66 最长公共子串
#include <iostream>
#include <vector> 
using namespace std;
string LCS66(string str1, string str2) {
    int LCSI;
    int LCSJ;
    int lcs = 0;
    if (str1.size() == 0 || str2.size() == 0) {
        return "";
    }
    vector<vector<int>> match(str1.size(), vector<int>(str2.size(), 0));
    for (int i = str1.size() - 1; i >= 0; i--) {
        for (int j = str2.size()-1; j >= 0; j--) {
            if (i == str1.size() - 1 || j == str2.size() - 1) {
                if (str1[i] == str2[j]) {
                    match[i][j] = 1;
                }
                else {
                    match[i][j] = 0;
                }
            }
            else {
                if (str1[i] == str2[j]) {
                    match[i][j] = match[i + 1][j + 1] + 1;
                }
                else {
                    match[i][j] = 0;
                }
            }
            if (match[i][j] > lcs) {
                lcs = match[i][j];
                LCSI = i;
                LCSJ = j;
            }
        }
    }
    return str1.substr(LCSI, lcs);
}