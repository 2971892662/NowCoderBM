//BM8 �����е������K���ڵ�
#include <stdlib.h>
struct ListNode {
    int val;
    ListNode* next;
};
ListNode* FindKthToTail(ListNode* pHead, int k) {
    if (pHead == NULL) {
        return NULL;
    }
    if (k <= 0) {
        return NULL;
    }
    ListNode* rear  = NULL;
    ListNode* head = NULL;
    head = pHead;
    rear = pHead;
    for (int i = 1; i <k; i++) {
        if (rear->next == NULL) {
            return NULL;
        }
        rear = rear->next;
    }
    while (rear->next !=  NULL) {
        rear = rear->next;
        head = head->next;
    }
    return head;
}