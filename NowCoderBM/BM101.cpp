//BM101 设计LFU缓存结构 Least Frequently Used

//??get和set的时间复杂度都是O(logn)

//双哈希表
#include <vector>
#include <unordered_map>
#include <iostream>

using namespace std;

struct DNode {
	int key;
	int val;
	int fre;
	DNode* pre;
	DNode* next;
};

struct DLinkedList {
	DNode* head;
};

void remove(DNode* temp) {
	temp->next->pre = temp->pre;
	temp->pre->next = temp->next;
}
void insertRear(DLinkedList* dll, DNode* d) {
	//尾插
	d->next = dll->head;
	d->pre = dll->head->pre;
	d->pre->next = d;
	dll->head->pre = d;
}

DNode* m_set(int key, int value, unordered_map<int, DNode*>& mpA, unordered_map<int, DLinkedList*>& mpB, int& lowfre) {
	//mpA为key-val哈希，mpB为fre-List哈希
	auto it = mpA.find(key);
	DNode* temp = it->second;
	temp->fre++;

	temp->val = value;
	remove(temp);
	auto ita = mpB.find(temp->fre);
	if (ita == mpB.end()) {
		DLinkedList* dll = new DLinkedList;
		DNode* tempa = new DNode;
		dll->head = tempa;
		dll->head->pre = tempa;
		dll->head->next = tempa;
		mpB.emplace(temp->fre, dll);
	}
	ita = mpB.find(temp->fre);
	insertRear(ita->second, temp);
	if (lowfre + 1 == temp->fre && mpB.find(lowfre)->second->head->next == mpB.find(lowfre)->second->head) {
		lowfre++;
	}
	return temp;
}
int get(int key, unordered_map<int, DNode*>& mpA, unordered_map<int, DLinkedList*>& mpB, int& lowfre) {
	auto it = mpA.find(key);
	int res = it->second->val;
	m_set(key, res, mpA, mpB, lowfre);
	return res;
}

class Solution {
private:
	unordered_map<int, DNode*> mpA;
	unordered_map<int, DLinkedList*> mpB;
	int capacity;
	int curr;
	int lowfre;
public:
	vector<int> LFU(vector<vector<int> >& operators, int k) {
		capacity = k;
		curr = 0;
		lowfre = 1;
		auto it = operators.begin();
		vector<int> result;
		for (it; it != operators.end(); it++) {
			if (*(it->begin()) == 1) {
				//set
				auto ita = mpA.find(*(it->begin() + 1));
				if (ita == mpA.end()) {
					//没数据
					if (curr < capacity) {
						//有容量
						curr++;
						DNode* temp = new DNode;
						temp->key = *(it->begin() + 1);
						temp->val = *(it->begin() + 2);
						temp->fre = 1;
						mpA.emplace(temp->key, temp);
						auto itm = mpB.find(temp->fre);
						if (itm == mpB.end()) {
							DLinkedList* dll = new DLinkedList;
							DNode* tempa = new DNode;
							dll->head = tempa;
							dll->head->pre = tempa;
							dll->head->next = tempa;
							mpB.emplace(temp->fre, dll);
						}
						itm = mpB.find(temp->fre);
						insertRear(itm->second, temp);
						lowfre = 1;
					}
					else {
						//没容量
						DNode* reused = mpB.find(lowfre)->second->head->next;
						remove(reused);
						mpA.erase(reused->key);
						mpA.emplace(*(it->begin() + 1), reused);
						reused->fre = 1;
						reused->key = *(it->begin() + 1);
						reused->val = *(it->begin() + 2);
						auto itm = mpB.find(reused->fre);
						if (itm == mpB.end()) {
							DLinkedList* dll = new DLinkedList;
							DNode* tempa = new DNode;
							dll->head = tempa;
							dll->head->pre = tempa;
							dll->head->next = tempa;
							mpB.emplace(reused->fre, dll);
						}
						itm = mpB.find(reused->fre);
						insertRear(itm->second, reused);
						lowfre = 1;
					}
				}
				else {
					//有数据
					m_set(*(it->begin() + 1), *(it->begin() + 2), mpA, mpB, lowfre);
				}
			}
			else {
				//get
				auto itb = mpA.find(*(it->begin() + 1));
				if (itb == mpA.end()) {
					//未出现或已删除
					result.push_back(-1);
				}
				else {
					//有数据
					result.push_back(get(*((it->begin()) + 1), mpA, mpB, lowfre));

				}
			}
		}
		return result;
	}
};

/*
int main() {
	Solution s;
	vector<vector<int>> mv = { {1, 1, 1},{1, 2, 2},{1, 3, 3},{1, 4, 4},{2,4},{2, 3},{2,2},{2,1}, {1, 5, 5},{2, 4} };
	vector<int> v = s.LFU(mv, 4);
}
*/

//:(
/*
1.自顶向下写代码
2.参数作为全局变量传递，不要做参数
3.初始化避免null
*/