#include <iostream>
#include <string.h>
#include <iostream>

using namespace std;
bool judge(string str) {
    int j = str.length() - 1;
    int i = 0;
    while (str[i] - str[j] == 0&&i<str.length()) {
        i++; j--;
    }
    if (i == str.length()) {
        return true;
    }
    else {
        return false;
    }
}

int main() {
    string str = "absba";
    judge(str);
}
