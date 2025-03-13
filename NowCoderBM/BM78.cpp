//BM78 打家劫舍
#include <vector>
using namespace std;
int rob78(vector<int>& nums) {
    /*并不是隔一个就抢是做优解
    int a = 0;
    int b = 0;
    for (int i = 0; i < nums.size(); i = i + 2) {
        a = a + nums[i];
    }
    for (int i = 1; i < nums.size(); i = i + 2) {
        b = b + nums[i];
    }
    return a >= b ? a : b;
    */
    if (nums.size() == 1) {
        return nums[0];
    }
    if (nums.size() == 2) {
        return nums[0] >= nums[1]?nums[0] : nums[1];
    }
    nums[1]= nums[0] >= nums[1] ? nums[0] : nums[1];    //nums[1]不一定是原值,毕竟是增序的
    for (int i = 2; i < nums.size(); i++) {
        nums[i] = nums[i - 1] >= nums[i - 2] + nums[i] ? nums[i - 1] : nums[i - 2] + nums[i];
    }
    return nums[nums.size() - 1];
}