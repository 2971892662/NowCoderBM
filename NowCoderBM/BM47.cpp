//BM47 寻找第K大
#include <vector>
using namespace std;
static int partition(vector<int>& arr, int low, int high) {
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
int findKth(vector<int>& a, int n, int K) {
    if (n == 0) {
        return 0;
    }
    int mid = partition(a, 0, n - 1);
    int low = 0;
    int high = n - 1;
    while (mid != n - K) {  //第K大，下标就是N-K
        if (mid < n - K) {
            mid = partition(a, mid + 1, high);
        }
        else {
            mid = partition(a, 0, mid - 1);
        }
    }
    return a[n - K];
}
