//BM1��ת����
struct ListNode {
    int val;
    ListNode* next;
};
ListNode* ReverseList(ListNode* head) {
    if (head == nullptr) {
        return nullptr;
    }
    ListNode* rear = nullptr;
    ListNode* front = nullptr;
    front = head;
    rear = front;
    while (rear->next != nullptr) {
        rear = rear->next;
    }
    ListNode* p = nullptr;
    while (front != rear) {
        p = front;
        front = front->next;
        p->next = rear->next;
        rear->next = p;
    }
    return rear;
}
//ÿ�ζ��ӱ�β��ǰ�ƶ��ǲ��õģ���Ϊ����������ȷ��ÿ�εı�βλ�ã������ͷԪ������ƶ���
/*
1   2   3   4   5
    2   3   4   5   1
        3   4   5   2   1
            4   5   3   2   1
                5   4   3   2   1
*/