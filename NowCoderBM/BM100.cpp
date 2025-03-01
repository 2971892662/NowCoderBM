//BM100 设计LRU缓存结构 least recently used

//end()函数返回一个指向容器最后一个元素之后的迭代器，而非最后一个元素的迭代器
#include <unordered_map>
using namespace std;

struct DNode {
	//双链表
	int key;
	int value;
	DNode* next;
	DNode* pre;
};
struct DLinkedList {
	DNode* head;
};
DLinkedList* initDLL() {
	DLinkedList* dll = new DLinkedList;
	DNode* first = new DNode;
	first->key = -1;
	first->value = -1;
	first->next = first;
	first->pre = first;
	dll->head = first;
	return dll;
}
void insertDNode(DLinkedList* dll, DNode* temp) {
	//头插
	temp->next = dll->head->next;
	dll->head->next->pre = temp;
	temp->pre = dll->head;
	dll->head->next = temp;
}

class Solution {
private:
	int capacity;
	int num;	//当前链表长度
	DLinkedList* dll;
	unordered_map<int, DNode*> mp;
public:
	Solution(int capacity) {
		this->capacity = capacity;
		this->num = 0;
		this->dll = initDLL();
	}

	int get(int key) {
		auto it = this->mp.find(key);
		if (it == this->mp.end()) {
			return -1;
		}
		int res = it->second->value;
		DNode* pos = it->second;
		//先删除
		pos->pre->next = pos->next;
		pos->next->pre = pos->pre;
		//再添加，实现移动
		pos->next = this->dll->head->next;
		this->dll->head->next->pre = pos;
		pos->pre = this->dll->head;
		this->dll->head->next = pos;
		return res;
	}

	void set(int key, int value) {
		auto it = this->mp.find(key);	//观察程序执行流是发现错误的好方法
		if (it == this->mp.end()) {
			//哈希表内无该键
			if (this->num < this->capacity) {
				//哈希表未满
				DNode* temp = new DNode;
				temp->key = key;
				temp->next = NULL;
				temp->pre = NULL;
				temp->value = value;
				insertDNode(this->dll, temp);
				this->mp.emplace(key, temp);
				this->num++;
				return;
			}
			else {
				//哈希表已满
				DNode* temp = this->dll->head->pre;
				temp->next->pre = temp->pre;
				temp->pre->next = temp->next;
				int oldkey = temp->key;
				temp->key = key;
				temp->value = value;
				insertDNode(this->dll, temp);
				this->mp.erase(oldkey);
				this->mp.emplace(key, temp);
				return;
			}
		}
		else {
			//哈希表内有该键
			DNode* temp = this->mp.find(key)->second;
			temp->value = value;
			temp->pre->next = temp->next;
			temp->next->pre = temp->pre;
			insertDNode(this->dll, temp);
			return;
		}
	}
};

/**
 * Your Solution object will be instantiated and called as such:
 * Solution* solution = new Solution(capacity);
 * int output = solution->get(key);
 * solution->set(key,value);
 */
