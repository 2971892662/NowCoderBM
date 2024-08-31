//BM16 删除链表中重复元素II
//给出一个升序排序的链表，删除链表中的所有重复出现的元素，只保留原链表中只出现一次的元素。
#include "ListNode.h"
#define MaxSize 10005

//统计每个值的出现次数
ListNode* deleteDuplicates15(ListNode* head) {
    if (head == NULL || head->next == NULL) {
        return head;
    }
    ListNode* front = head;
    ListNode* rear = front->next;
    int value[MaxSize];
    int count[MaxSize];
    int i = 0;
    value[i] = front->val;
    count[i] = 1;
    while (rear != NULL) {
        if (front->val != rear->val) {
            i++;
            value[i] = rear->val;
            count[i] = 1;
            front = front->next;
            rear = rear->next;
            continue;
        }
        ListNode* p = rear;
        value[i] = front->val;
        count[i]++;
        rear = rear->next;
        front->next = rear;
        free(p);
    }
    int j = 0;
    while (count[j] != 1&&j<=i) {
        j++;
    }
    if (j > i) {
        return NULL;
    }
    ListNode* h = (ListNode*)malloc(sizeof(ListNode));
    h->next = NULL;
    h->val = value[j];
    j++;
    ListNode* re = h;
    for (j; j <= i; j++) {
        if (count[j] == 1) {
            ListNode* t = (ListNode*)malloc(sizeof(ListNode));
            t->val = value[j];
            t->next = NULL;
            re->next = t;
            re = re->next;
        }
    }
    return h;
}