//BM4�ϲ�������������
#include <stdlib.h>
struct ListNode {
    int val;
    ListNode* next;
};
//�ϲ�����
ListNode* Merge(ListNode* pHead1, ListNode* pHead2) {
    if (pHead1 == NULL && pHead2 != NULL) {
        return pHead2;
    }
    if (pHead1 != NULL && pHead2 == NULL) {
        return pHead1;
    }
    if (pHead1 == NULL && pHead2 == NULL) {
        return pHead1;
    }
    ListNode* a = pHead1;
    ListNode* b = pHead2;
    ListNode* rear = NULL;
    if (a->val <= b->val) {
        rear = a;
        a = a->next;
    }
    else {
        rear = b;
        b = b->next;
    }
    ListNode* head = rear;
    while (a != NULL && b != NULL) {
        if (a->val <= b->val) {
            rear->next = a;
            a = a->next;
            rear = rear->next;
        }
        else {
            rear->next = b;
            b = b->next;
            rear = rear->next;
        }
    }
    if (a != NULL) {
        rear->next = a;
    }
    if (b != NULL) {
        rear->next = b;
    }
    return head;
}
//��Ӧ��ֱ��ȷ��ʹ��phead1����phead2��Ϊ����ֵ����Ϊ���ߵ�һ���ֵ�Ĺ�ϵ����ȷ��������ʹ��rear������