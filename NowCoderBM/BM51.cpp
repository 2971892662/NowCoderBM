//BM51 数组中超过一半的数

#include <vector>
#include <unordered_map>

using namespace std;

int MoreThanHalfNum_Solution(vector<int>& numbers) {
    //法一：快排后中间的必为超过一半的数 时间复杂度O(log2N)
    //法二：哈希表 空间复杂度O(N)
    unordered_map<int, int> mp;
    for (int i = 0; i < numbers.size(); i++) {
        auto it = mp.find(numbers[i]);
        if (it == mp.end()) {
            mp.emplace(numbers[i], 1);
            if (mp[numbers[i]] > numbers.size() / 2) {
                return numbers[i];
            }
        }
        else {
            mp[numbers[i]]++;
            if (mp[numbers[i]] > numbers.size() / 2) {
                return numbers[i];
            }
        }
    }
    return -1;
}