//BM10两个链表的第一个公共节点
#include <stdlib.h>
struct ListNode {
	int val;
	ListNode* next;
};
ListNode* FindFirstCommonNode(ListNode* pHead1, ListNode* pHead2) {
	if (pHead1 == NULL || pHead2 == NULL) {
		return NULL;
	}
	int lenA = 1;
	int lenB = 1;
	ListNode* La = pHead1;
	ListNode* Lb = pHead2;
	while (La->next != NULL) {	//用while而不是if循环
		lenA++;
		La = La->next;
	}
	while (Lb->next != NULL) {
		lenB++;
		Lb = Lb->next;
	}
	int diff = lenA - lenB;	//不是La-Lb
	La = pHead1;
	Lb = pHead2;
	if (diff > 0) {
		for (int i = 0; i < diff; i++) {
			La = La->next;
		}
	}
	else if (diff < 0) {
		for (int i = 0; i < (-diff); i++) {
			Lb = Lb->next;
		}
	}
	while (La != NULL) {
		if (La == Lb) {
			return La;
		}
		La = La->next;
		Lb = Lb->next;
	}
	return NULL;
}
/*
int main() {
	int a[] = {1,2,3};
	int b[] = { 4,5 };
	int c[] = { 6,7 };
	ListNode* ra, * rb, * rc;
	ListNode* La = createLink(a, 3,ra);
	ListNode* Lb = createLink(b, 2,rb);
	ListNode* Lc = createLink(c, 2,rc);
	ra->next = Lc;
	rb->next = Lc;
	ListNode* res=FindFirstCommonNode(La, Lb);
}
*/