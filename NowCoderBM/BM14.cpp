//BM14 链表的奇偶重拍
//将链表的奇数位节点和偶数位节点分别放在一起，重排后输出
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
    evenRear->next = NULL;  //缺少这一句在链长为奇数是会组成有环链
    oddRear->next = even;
    return odd;
}