//BM45 �������ڵ����ֵ
//ʱ�ո��Ӷȶ�Ҫ����O��n���������ƽ�O(size*n)

#include <vector>
using namespace std;
vector<int> maxInWindows(vector<int>& num, int size) {
    vector<int> res;
    if (size <= 0){
        return res;
    }
    if (size > num.size()) {
        return res;
    }
    int max=-1;
    for (int i = 0; i < num.size() - size + 1; i++) {
        for (int j = 0; j < size; j++) {
            if (num[i + j] > max) {
                max = num[i + j];
            }
        }
        res.push_back(max);
        max = -1;
    }
    return res;
}
//����ʹ��˫�˶�����������ʱ��˼��һ��
