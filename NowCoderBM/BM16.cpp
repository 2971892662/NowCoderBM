//BM16 ɾ���������ظ�Ԫ��II
//����һ���������������ɾ�������е������ظ����ֵ�Ԫ�أ�ֻ����ԭ������ֻ����һ�ε�Ԫ�ء�
#include "ListNode.h"
#define MaxSize 10005

//ͳ��ÿ��ֵ�ĳ��ִ���
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