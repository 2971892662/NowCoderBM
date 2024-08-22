//BM7 链表中环的入口
#include <stdlib.h>
struct ListNode {
	int val;
	ListNode* next;
};
ListNode* EntryNodeOfLoop(ListNode* pHead) {
	if (pHead == NULL) {
		return NULL;
	}
	ListNode* fast = pHead;
	ListNode* slow = pHead;
	while (fast != NULL) {
		if (fast->next == NULL) {
			return NULL;
		}
		fast = fast->next;
		if (fast->next == NULL) {
			return NULL;
		}
		fast = fast->next;
		slow = slow->next;
		if (fast == slow) {
			break;
		}
	}
	ListNode* p = pHead;
	while (p != fast) {
		p = p->next;
		fast = fast->next;
	}
	return fast;
}