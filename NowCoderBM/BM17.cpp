//BM17 �۰����/���ֲ���
#include <vector>
using namespace std;
int search(vector<int>& nums, int target) {
    int low = 0;
    int high = nums.size() - 1;
    int mid = 0;
    while (low <= high) {
        mid = (low + high) / 2;
        if (nums[mid] == target) {
            return mid;
        }
        if (nums[mid] < target) {
            low = mid + 1;
        }
        else {
            high = mid - 1;
        }
    }
    return -1;
}