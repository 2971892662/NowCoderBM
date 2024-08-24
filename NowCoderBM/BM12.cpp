//BM12 单链表的排序
#include <stdio.h>
#include <stdlib.h>
#define MaxSize 100000
struct ListNode {
	int val;
	ListNode* next;
};
int* quickSort(int* a, int start, int end) {
	int pivot = a[start];
	int m = start;
	int n = end;
	if (start == end) {
		return a;
	}
	while (start < end) {
		while (a[end] > pivot && start < end) {
			end--;
		}
		a[start] = a[end];
		while (a[start] <= pivot && start < end) {
			start++;
		}
		a[end] = a[start];
	}
	a[start] = pivot;
	//直接在排序函数内进行递归操作
	if (m <= start - 1) {
		quickSort(a, m, start - 1);
	}
	if (start + 1 <= n) {
		quickSort(a, start + 1, n);
	}
	//这两个if判断是很有必要的
	return a;
}
ListNode* sortInList(ListNode* head) {
	if (head == NULL) {
		return NULL;
	}
	//int a[100000];
	//int类型数组的最大长度大概是字符类型的四分之一，为536698431
	int* a = (int*)malloc(sizeof(int) * MaxSize);
	int i = 0;
	ListNode* p = head;
	while (p != NULL) {
		a[i] = p->val;
		i++;
		p = p->next;
	}
	quickSort(a, 0, i - 1);
	//尾插法
	ListNode* mhead = (ListNode*)malloc(sizeof(ListNode));
	mhead->val = a[0];
	mhead->next = NULL;
	ListNode* rear = mhead;
	for (int k = 1; k < i; k++) {
		ListNode* s = (ListNode*)malloc(sizeof(ListNode));
		s->val = a[k];
		s->next = NULL;
		rear->next = s;
		rear = rear->next;
	}
	return mhead;
}