//BM13 �ж������Ƿ��ǻ�������
#include <stdlib.h>
struct ListNode {
    int val;
    ListNode* next;
};
bool isPail(ListNode* head) {
    //�洢�������У����Ա���������������ʵ�����
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