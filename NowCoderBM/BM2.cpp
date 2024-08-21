//BM2链表内指定区间反转
#include <stdlib.h>
struct ListNode {
    int val;
    ListNode* next;
};
ListNode* reverseBetween(ListNode* head, int m, int n) {
    ListNode* p = head;
    int i = 1;
    ListNode* s;
    if (m == 1) {
        s = NULL;
    }
    else {
        while (i < m - 1) {
            p = p->next;
            i++;
        }
        s = p;
    }
    while (i < m) {
        p = p->next;
        i++;
    }
    ListNode* front = p;
    while (i < n) {
        p = p->next;
        i++;
    }
    ListNode* rear = p;
    ListNode* t = rear->next;
    ListNode* temp = NULL;
    while (front != rear) {
        temp = front;
        front = front->next;
        temp->next = rear->next;
        rear->next = temp;
    }
    if (s != NULL) {
        s->next = rear;
        return head;
    }
    else {
        return rear;
    }
}