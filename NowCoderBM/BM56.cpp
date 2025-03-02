//BM56 有重复项数字的全排列

#include <vector>
using namespace std;
void select56(vector<int>& num, vector<int>& res, vector<vector<int>>& finalres) {
    if (num.empty()) {
        finalres.push_back(res); // 如果 num 为空，说明当前排列完成，加入结果集
        return;
    }
    for (int i = 0; i < num.size(); i++) {
        // 如果当前元素与前一个元素相同，且前一个元素已经被使用过，则跳过
        if (i > 0 && num[i] == num[i - 1]) {
            continue;
        }
        int temp = num[i];
        res.push_back(temp); // 将当前元素加入当前排列
        num.erase(num.begin() + i); // 从剩余元素中移除当前元素
        select56(num, res, finalres); // 递归生成剩余元素的排列
        num.insert(num.begin() + i, temp); // 恢复 num 的状态
        res.pop_back(); // 恢复 res 的状态
        //回溯：先添加，再删除,以进行下一轮for循环；使用引用而非参数副本传递
        /*问题代码分析：
            for (int i = 0; i < num.size(); i++) {
                if (i > 0 && num[i] == num[i - 1]) {
                    continue;
                }
                int temp = num[i];
                res.push_back(temp); 
                num.erase(num.begin() + i); 
                select56(num, res, finalres); 
            }
        循环体内的num.erase()虽然作为形参传给子递归没问题，但是会影响同级的递归，而且也影响了循环判断条件。
        同样res也会带来影响，所以要添加：
            num.insert(num.begin() + i, temp);
            res.pop_back();
        总结：还不如直接处理全局变量，对全局变量进行增删。
        */
    }
}


int partition(int* arr, int low, int high) {    //快排还是要多熟悉
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

void quickSortVector(int a[], int low, int high) {
    if (low < high) {
        int mid = partition(a, low, high);
        quickSortVector(a, low, mid - 1);
        quickSortVector(a, mid + 1, high);
    }
}

vector<vector<int> > permuteUnique(vector<int>& num) {
    vector<int> res;
    vector<vector<int>> finalres;
    //vector的排序：sort(num.begin(), num.end()); 
    int* a = new int[num.size()];
    for (int i = 0; i < num.size(); i++) {
        a[i] = num[i];
    }
    quickSortVector(a, 0, num.size() - 1);
    for (int i = 0; i < num.size(); i++) {
        num[i] = a[i];
    }
    select56(num, res, finalres);
    return finalres;
}
