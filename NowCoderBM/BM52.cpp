//BM52 只出现一次的两个数字
#include<vector>
#include <unordered_map>
using namespace std;
vector<int> FindNumsAppearOnce(vector<int>& nums) {
    unordered_map<int, int> mp;
    for (int i = 0; i < nums.size(); i++) {
        auto it = mp.find(nums[i]);
        if (it == mp.end()) {
            mp.emplace(nums[i], 1);
        }
        else {
            mp[nums[i]]++;
        }
    }
    vector<int> res;
    for (auto it = mp.begin(); it != mp.end(); it++) {
        if (it->second == 1) {
            res.push_back(it->first);
        }
    }

    if (res[0] <= res[1]) {
        return res;
    }
    else {
        //不使用中间变量交换
        res[0] = res[0] + res[1];
        res[1] = res[0] - res[1];
        res[0] = res[0] - res[1];
        return res;
    }
}