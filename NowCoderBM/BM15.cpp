//BM15 ɾ�������е��ظ�Ԫ��I
//ɾ�����������е��ظ�Ԫ�أ�������Ԫ�ش�С�������򣩣�ʹ�����е�����Ԫ�ض�ֻ����һ��

#include <stdlib.h>
#include "ListNode.h"
ListNode* deleteDuplicates16(ListNode* head) {
    if (head == NULL || head->next == NULL) {
        return head;
    }
    ListNode* front = head;
    ListNode* rear = front->next;
    while (rear != NULL) {
        if (front->val != rear->val) {
            front = front->next;
            rear = rear->next;
            continue;
        }
        ListNode* p = rear;
        rear = rear->next;
        front->next = rear;
        free(p);
    }
    return head;
}
