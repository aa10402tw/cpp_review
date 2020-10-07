#include <iostream>
#include <string>

struct ListNode {
	int val;
	ListNode* next;
	ListNode() : val(0), next(nullptr) {}
	ListNode(int x) : val(x), next(nullptr) {}
	ListNode(int x, ListNode* next) : val(x), next(next) {}
	
};

ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
	int sum = 0;
	int carry = 0;
	ListNode* head = new ListNode();
	ListNode* tail = head;
	ListNode* prev = nullptr;
	while (l1 != nullptr || l2 != nullptr) {
		if (l1 != nullptr) {
			sum += l1->val;
			l1 = l1->next;
		}
		if (l2 != nullptr) {
			sum += l2->val;
			l2 = l2->next;
		}
		sum += carry;
		carry = (sum >= 10) ? 1 : 0;
		sum %= 10;
		tail->val = sum;
		sum = 0;
		if (prev != nullptr)
			prev->next = tail;
		prev = tail;
		tail = new ListNode();
	}
	if (carry > 0) {
		tail->val = carry;
		prev->next = tail;
	}
	return head;
}

void printLinkedList(ListNode* l) {
	while (l != nullptr) {
		std::cout << l->val;
		if (l->next != nullptr)
			std::cout << "->";
		l = l->next;
	}
	std::cout << std::endl;
}

int main() {
	ListNode* n1 = new ListNode(2);
	ListNode* n2 = new ListNode(4);
	ListNode* n3 = new ListNode(3);
	n1->next = n2;
	n2->next = n3;
	printLinkedList(n1);

	ListNode* n4 = new ListNode(5);
	ListNode* n5 = new ListNode(6);
	ListNode* n6 = new ListNode(4);
	n4->next = n5;
	n5->next = n6;
	printLinkedList(n4);

	ListNode* l = addTwoNumbers(n1, n4);
	printLinkedList(l);
}
