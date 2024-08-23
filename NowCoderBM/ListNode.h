#include <stdlib.h>
#include <iostream>
using namespace std;
struct ListNode {
	int val;
	ListNode* next;
};
ListNode* createLink(int* a, int len, ListNode*& rear);
