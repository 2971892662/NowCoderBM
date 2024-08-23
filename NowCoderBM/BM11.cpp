//链表相加
#include <stdlib.h>
struct ListNode {
    int val;
    ListNode* next;
};
ListNode* reversrListNode(ListNode* head) {
    if (head == NULL) {
        return NULL;
    }
    ListNode* rear = head;
    while (rear->next != NULL) {
        rear = rear->next;
    }
    ListNode* he = head;
    ListNode* p = head;
    while (he != rear) {
        p = he;
        he = he->next;
        p->next = rear->next;
        rear->next = p;
    }
    return rear;
}
ListNode* addInList(ListNode* head1, ListNode* head2) {
    if (head1 == NULL && head2 != NULL) {
        return head2;
    }
    if (head1 != NULL && head2 == NULL) {
        return head1;
    }
    if (head1 == NULL && head2 == NULL) {
        return NULL;
    }
    //链表长度是一个非常有用的信息
    //反转链表法
    ListNode* h1 = reversrListNode(head1);
    ListNode* h2 = reversrListNode(head2);
    ListNode* res = (ListNode*)malloc(sizeof(ListNode));
    res->next = NULL;
    int m = 0;  //进位
    int n = 0;  //余数
    m = (h1->val + h2->val) / 10;
    n = (h1->val + h2->val) % 10;
    res->val = n;
    h1 = h1->next;
    h2 = h2->next;
    ListNode* rear = res;
    while (h1 != NULL || h2 != NULL || m != 0) {
        ListNode* p = (ListNode*)malloc(sizeof(ListNode));
        if (h1 != NULL && h2 == NULL) {
            n = (h1->val + m) % 10;
            m = (h1->val + m) / 10;
            p->next = NULL;
            p->val = n;
            rear->next = p;
            rear = rear->next;
            h1 = h1->next;
            continue;
        }
        if (h1 == NULL && h2 != NULL) {
            n = (h2->val + m) % 10;
            m = (h2->val + m) / 10;
            p->next = NULL;
            p->val = n;
            rear->next = p;
            rear = rear->next;
            h2 = h2->next;
            continue;
        }
        if (h1 == NULL && h2 == NULL) {
            m = 0;
            n = 1;
            p->next = NULL;
            p->val = n;
            rear->next = p;
            rear = rear->next;
            continue;
        }
        if (h1 != NULL && h2 != NULL) {
            n = (h1->val + h2->val + m) % 10; //有问题，这两行调换一下位置就行了。m值会变，所以后执行
            m = (h1->val+h2->val + m) / 10;
            p->next = NULL;
            p->val = n;
            rear->next = p;
            rear = rear->next;
            h1 = h1->next;
            h2 = h2->next;
            continue;
        }
    }
    return reversrListNode(res);
}
/*
int main() {
    int a[] = { 5,4,4,0 };
    ListNode* p = NULL;
    ListNode* la=createLink(a, 4, p);
    int b[] = { 4,9,3,6};
    ListNode* lb = createLink(b, 4, p);
    ListNode* result= addInList(la, lb);
}
*/