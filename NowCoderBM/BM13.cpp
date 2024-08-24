//BM13 判断链表是否是回文链表
#include <stdlib.h>
struct ListNode {
    int val;
    ListNode* next;
};
bool isPail(ListNode* head) {
    //存储到数组中（线性表），利用其随机访问的特性
    if (head == NULL) {
        return true;
    }
    int* a = (int*)malloc(sizeof(int) * 100000);
    ListNode* p = head;
    int i = 0;
    while (p != NULL) {
        a[i] = p->val;
        p = p->next;
        i++;
    }
    int j = 0;
    i--;
    while (j<=i) {
        if (a[i] != a[j]) {
            return false;
        }
        i--;
        j++;
    }
    return true;
}