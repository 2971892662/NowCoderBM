//BM5 �ϲ�K�������������
#include <iostream>
#include <vector>
using namespace std;
struct ListNode {
	int val;
	struct ListNode* next;
};
ListNode* mergeKLists(vector<ListNode*>& lists) {
	if (lists.size() == 0) {
		return nullptr;
	}
	while (lists.size() != 1) {
		for (int i = 0, j = lists.size() / 2; i < lists.size() / 2; i++, j++) {
			ListNode* h1 = lists[i];
			ListNode* h2 = lists[j];
			ListNode* rear = nullptr;
			ListNode* head = nullptr;
			//������������ж�
			if (h1 == nullptr && h2 != nullptr) {
				lists[i] = h2;
				continue;
			}
			if (h2 == nullptr && h1 != nullptr) {
				lists[i] = h1;
				continue;
			}
			if (h2 == nullptr && h1 == nullptr) {
				lists[i] = nullptr;
				continue;
			}
			if (h1->val <= h2->val) {
				head = h1;
				rear = h1;
				h1 = h1->next;
			}
			else {
				head = h2;
				rear = h2;
				h2 = h2->next;
			}
			while (h1 != nullptr && h2 != nullptr) {
				if (h1->val <= h2->val) {
					rear->next = h1;
					h1 = h1->next;
					rear = rear->next;
				}
				else {
					rear->next = h2;
					h2 = h2->next;
					rear = rear->next;
				}
			}
			if (h1 != nullptr) {
				rear->next = h1;
			}
			if (h2 != nullptr) {
				rear->next = h2;
			}
			lists[i] = head;
		}
		if (lists.size() % 2 == 1) {	//��%�Ƚ�����������/��Ŷ
			lists.erase(lists.begin() + lists.size() / 2, lists.begin() + lists.size() - 1);
		}
		else {
			lists.erase(lists.begin() + lists.size() / 2, lists.begin() + lists.size());
		}
		cout << 1 << endl;
		//erase��Χɾ����begin,end��->[begin,end-1]
		//erase���ɾ���ᵼ�±�ɾ��Ԫ�غ��������Ԫ��������ǰ�ƶ�
	}
	return lists[0];
}