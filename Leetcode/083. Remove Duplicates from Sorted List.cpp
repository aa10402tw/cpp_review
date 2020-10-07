#include <iostream>

struct ListNode {
	int val;
	ListNode* next;
	ListNode() : val(0), next(nullptr) {}
	ListNode(int x) : val(x), next(nullptr) {}
	ListNode(int x, ListNode* next) : val(x), next(next) {}
};

ListNode* deleteDuplicates(ListNode* head) {
	ListNode* cur = head;
	ListNode* prev = nullptr;
	while (cur != nullptr) {
		if (prev != nullptr && prev->val == cur->val) {
			cur = cur->next;
			prev->next = cur;
			continue;
		}
		prev = cur;
		cur = cur->next;
	}
	return head;
}

void printList(ListNode* l) {
	while (l != nullptr) {
		std::cout << l->val;
		if (l->next != nullptr)
			std::cout << "->";
		l = l->next;
	}
	std::cout << std::endl;
}

int main() {
	ListNode* l1 = new ListNode(1);
	ListNode* l2 = new ListNode(1);
	ListNode* l3 = new ListNode(2);
	l1->next = l2;
	l2->next = l3;
	printList(l1);

	l1 = deleteDuplicates(l1);
	printList(l1);
}
