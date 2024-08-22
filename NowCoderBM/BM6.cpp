//BM6 链表中是否有环
#include <stdlib.h>
using namespace std;
struct ListNode {
	int val;
	ListNode* next;
};
bool hasCycle(ListNode* head) {
	if (head == NULL) {
		return false;
	}
	ListNode* front = NULL;
	ListNode* rear = NULL;
	front = head;
	rear = head;
	while (rear != NULL) {
		if (rear->next == NULL) {
			return false;
		}
		rear = rear->next;
		if (rear->next == NULL) {
			return false;
		}
		rear = rear->next;
		front = front->next;
		if (front == rear) {
			return true;
		}
	}
	return false;
}
//使用快慢指针，快指针每次移动两次，慢指针每次移动一次，如存在环二者必能相遇，但相遇节点不一定是环的入口。