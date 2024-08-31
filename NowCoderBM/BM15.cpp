//BM15 删除链表中的重复元素I
//删除给出链表中的重复元素（链表中元素从小到大有序），使链表中的所有元素都只出现一次

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
