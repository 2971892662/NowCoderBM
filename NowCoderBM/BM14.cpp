//BM14 �������ż����
//�����������λ�ڵ��ż��λ�ڵ�ֱ����һ�����ź����
#include <stdlib.h>
struct ListNode {
    int val;
    ListNode* next;
};
ListNode* oddEvenList(ListNode* head) {
    if (head == NULL) {
        return NULL;
    }
    ListNode* odd = NULL;
    ListNode* even = NULL;
    ListNode* p = head;
    odd = p;
    p = p->next;
    if (p == NULL) {
        return odd;
    }
    even = p;
    ListNode* oddRear = odd;
    ListNode* evenRear = even;
    ListNode* s = NULL;
    p = p->next;
    while (p != NULL) {
        s = p;
        p = p->next;
        oddRear->next = s;
        oddRear = oddRear->next;
        if (p == NULL) {
            break;
        }
        s = p;
        p = p->next;
        evenRear->next = s;
        evenRear = evenRear->next;
    }
    evenRear->next = NULL;  //ȱ����һ��������Ϊ�����ǻ�����л���
    oddRear->next = even;
    return odd;
}