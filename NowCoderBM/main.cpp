#include <iostream>
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
		if (rear->next== NULL) {
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
int main() {
	ListNode* p = (ListNode*)malloc(sizeof(ListNode));
	p->next = NULL;
	p->val = -1;
	cout<<hasCycle(p);
}