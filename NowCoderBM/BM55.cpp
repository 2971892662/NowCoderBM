//BM55 没有重复项数字的全排列
//回溯 递归


#include <vector>

using namespace std;

void select(vector<int> num, vector<int> res, vector<vector<int> >& finalres) {
    int temp;
    if (num.size() > 0) {
        for (int k = 0; k < num.size(); k++) {
            /*
            //有问题，修改会影响后续（指同一级别的for循环）的递归调用。
            temp = num[k];
            num.erase(num.begin() + k);
            res.push_back(temp);
            select(num, res, finalres);
            */
            int temp = num[k];
            vector<int> new_num = num;  // 创建 num 的副本
            new_num.erase(new_num.begin() + k);  // 从副本中删除当前元素
            vector<int> new_res = res;  // 创建 res 的副本
            new_res.push_back(temp);  // 将当前元素添加到 res 的副本中
            select(new_num, new_res, finalres);  // 递归调用
        }
    }
    else {
    finalres.push_back(res);
    }
}

vector<vector<int> > permute(vector<int>& num) {
    vector<vector<int> > finalres;
    vector<int> res;
    select(num, res, finalres);
    return finalres;
}