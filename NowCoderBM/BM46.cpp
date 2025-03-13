//BM46 最小的K个数
#include <vector>
using namespace std;
int partition(vector<int>& arr, int low, int high) {
    int pivot = arr[low];
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
vector<int> GetLeastNumbers_Solution(vector<int>& input, int k) {
    if (input.size() == 0) {
        vector<int> a(0);
        return a;
    }
    int mid = partition(input, 0, input.size() - 1);
    while (mid != k) {
        if (mid < k) {
            mid = partition(input, mid + 1, input.size() - 1);
        }
        else {
            mid = partition(input, 0, mid - 1);
        }
    }
    vector<int> res(0);
    for (int i = 0; i < k; i++) {
        res.push_back(input[i]);
    }
    return res;
}