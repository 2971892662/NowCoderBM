#include "ListNode.h"
ListNode* createLink(int* a, int len, ListNode*& rear) {
	rear = NULL;
	if (len <= 0) {
		return NULL;
	}
	ListNode* head = (ListNode*)malloc(sizeof(ListNode));
	head->next = NULL;
	head->val = a[0];
	rear = head;
	for (int i = 1; i < len; i++) {
		ListNode* p = (ListNode*)malloc(sizeof(ListNode));
		p->next = NULL;
		p->val = a[i];
		rear->next = p;
		rear = rear->next;
	}
	return head;
}