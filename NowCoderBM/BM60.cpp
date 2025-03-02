
//BM60 括号生成
#include <vector>
#include <string>
using namespace std;

/*错误的方法：找位置插入一队"()",会出现重复
void select(int n, string& res, vector<string>& finalRes) {
    if (n == 0) {
        finalRes.push_back(res);
    }
    else {
        if (res.length() == 0) {
            res.insert(res.begin(), '(');
            res.insert(res.begin()+1, ')');
            select(n - 1, res, finalRes);
            res.erase(res.begin());
            res.erase(res.begin());
        }
        else {
            for (int i = 1; i <= res.length(); i++) {
                res.insert(res.begin() + i, '(');
                res.insert(res.begin() + i + 1, ')');
                select(n - 1, res, finalRes); //n--会影响n值
                res.erase(res.begin() + i);
                res.erase(res.begin() + i);
            }
        }
    }
}
vector<string> generateParenthesis(int n) {
    string res = "";
    vector<string> finalRes;
    select(n, res, finalRes);
    return finalRes;
}

*/

//在尾部插入括号
void tailInsert(int left, int right, string &str, vector<string> &finalres,int n) {
    if (left<n) {
        str.insert(str.end(),'(');
        tailInsert(left+1, right, str, finalres,n);
        str.pop_back();
    }
    if (right < n && left > right) {
        str.insert(str.end(), ')');
        tailInsert(left, right + 1, str, finalres, n);
        str.pop_back();
    }
    if (left == n && right == n) {
        finalres.push_back(str);
    }
}

vector<string> generateParenthesis(int n) {
    string str = "";
    vector<string> finalres;
    tailInsert(0, 0, str, finalres, n);
    return finalres;
}