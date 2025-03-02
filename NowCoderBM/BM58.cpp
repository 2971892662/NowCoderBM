//BM58 字符串的全排列
#include <vector>
#include <string>
using namespace std;

int partition58(char* arr, int low, int high) {    
    char pivot = arr[low];
    while (low < high) {
        while (low < high && arr[high] >= pivot) {
            high--;
        }
        arr[low] = arr[high];
        while (low < high && arr[low] <= pivot) {
            low++;
        }
        arr[high] = arr[low];
    }
    arr[low] = pivot;
    return low;
}

void quickSort58(char* a, int low, int high) {
    if (low < high) {
        int mid = partition58(a, low, high);
        quickSort58(a, low, mid - 1);
        quickSort58(a, mid + 1, high);
    }
}

void select(string& str, string& res, vector<string>& finalRes) {
    if (str.length() == 0) {
        finalRes.push_back(res);
    }
    if(str.length() > 0) {
        for (int i = 0; i < str.length(); i++) {
            if (i > 0 && str[i] == str[i - 1]) {    //前后两次不重复选择就可以保证结果不重复
                continue;
            }
            res = res + str[i];
            str.erase(str.begin() + i);
            select(str, res, finalRes);
            str.insert(str.begin() + i, res.back());
            res.pop_back();
        }
    }
}

vector<string> Permutation(string str) {
    char* a = new char[str.length()];
    str.copy(a, str.length(), 0);
    quickSort58(a, 0, str.length() - 1);
    str = a;
    string res = "";
    vector<string> finalRes;
    select(str, res, finalRes);
    return finalRes;
}