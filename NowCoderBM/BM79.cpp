//BM79 打家劫舍二
#include <vector>
using namespace std;
int rob79(vector<int>& nums) {
    if (nums.size() == 1) {
        return nums[0];
    }
    if (nums.size() == 2) {
        return nums[0] >= nums[1] ? nums[0] : nums[1];
    }
    vector<int> a(nums.size(), 0);
    a[0] = nums[0];
    a[1] = nums[0] >= nums[1] ? nums[0] :nums[1];   //nums[1]不一定是原值,毕竟是增序的
    for (int i = 2; i < nums.size(); i++) {
        a[i] = a[i - 1] >= a[i - 2] + nums[i] ? a[i - 1] : a[i - 2] +nums[i];
    }
    vector<int> b(nums.size(), 0);
    b[1] = nums[1];
    b[2]= nums[1] >= nums[2] ? nums[1] : nums[2];
    for (int i = 3; i < nums.size(); i++) {
        b[i] = b[i - 1] >= b[i - 2] + nums[i] ? b[i - 1] : b[i - 2] + nums[i];
    }
    return a[nums.size() - 2] > b[nums.size() - 1] ? a[nums.size() - 2] : b[nums.size() - 1];
}
//避开环，进行分类讨论