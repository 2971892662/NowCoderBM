//BM53 缺失的第一个正数
#include <vector>
#include <unordered_map>
using namespace std;
int minNumberDisappeared(vector<int>& nums) {
    unordered_map<int, bool> mp;
    for (int i = 0; i < nums.size(); i++) {
        if (mp.find(nums[i]) == mp.end()) {
            mp.emplace(nums[i], true);
        }
    }
    for (int i = 1; i <= nums.size() + 1; i++) {
        if (mp.find(i) == mp.end()) {
            return i;
        }
    }
    return -1;
    //不加会导致错误：non-void function does not return a value in all control paths [-Werror,-Wreturn-type]
    //牛客的编译器看来比较严谨
}