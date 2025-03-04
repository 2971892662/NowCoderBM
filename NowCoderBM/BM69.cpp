//BM69 把数字翻译成字符串
#include <string>
#include <vector>

/*失败总结：
1.这题从后往前进行动态规划是行不通的，因为遇到0时不知道前面是多少，10/20是可行的，00/30-90则是0
所以只能从前往后进行线性规划
2.先剔除不符合的，在循环内判断比较麻烦
*/

using namespace std;

int solve69(string nums) {
    if (nums.size() == 0 || nums[0] == '0') {
        return 0;
    }
    if (nums.size() == 1) {
        return 1;
    }

    // 检查是否有无效的0
    for (int i = 1; i < nums.size(); i++) {
        if (nums[i] == '0' && (nums[i - 1] != '1' && nums[i - 1] != '2')) {
            return 0;
        }
    }

    vector<int> count(nums.size(), 0);
    count[0] = 1;

    // 初始化 count[1]
    if ((nums[0] == '1' &&nums[1]!='0') || (nums[0] == '2' && nums[1] <= '6'&& nums[1] != '0')) {   //10和20应得1
        count[1] = 2;
    }
    else {
        count[1] = 1;
    }

    // 动态规划
    for (int i = 2; i < nums.size(); i++) { //使用了两次if并自增,即将f=f+f分两次做，这样确实能不那么复杂
        if (nums[i] != '0') {
            count[i] += count[i - 1];
        }
        if (nums[i - 1] == '1' || (nums[i - 1] == '2' && nums[i] <= '6')) {
            count[i] += count[i - 2];
        }
    }

    return count[nums.size() - 1];
}