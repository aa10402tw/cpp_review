/* [Question Description]
Merge two sorted linked lists and return it as a new sorted list. The new list should be made by splicing together the nodes of the first two lists.

# Example 1
Input: l1 = [1,2,4], l2 = [1,3,4]
Output: [1,1,2,3,4,4]

# Example 2
Input: l1 = [], l2 = []
Output: []

# Example 3
Input: l1 = [], l2 = [0]
Output: [0]
*/ 
#include <iostream>

/*
Merge two sorted linked lists and return it as a new sorted list. 
The new list should be made by splicing together the nodes of the first two lists.

Input: l1 = [1,2,4], l2 = [1,3,4]
Output: [1,1,2,3,4,4]
*/ 


struct ListNode {
	int val;
	ListNode* next;
	ListNode() : val(0), next(nullptr) {}
	ListNode(int x) : val(x), next(nullptr) {}
	ListNode(int x, ListNode* next) : val(x), next(next) {}
};

void printLinkedList(ListNode* l) {
	while (l != nullptr) {
		std::cout << l->val;
		if (l->next != nullptr) {
			std::cout << "->";
		}
		l = l->next;
	}
	std::cout << std::endl;
}

ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
	if (l1 == nullptr && l2 == nullptr) return nullptr; // both empty
	if (l1 == nullptr) return l2; // l1 empty
	if (l2 == nullptr) return l1; // l2 empty

	ListNode* head = new ListNode(); // before real head
	ListNode* cur = head;
	ListNode* prev = nullptr;
	
	while (l1 != nullptr || l2 != nullptr) {
		if (l1 == nullptr) {
			cur->val = l2->val;
			l2 = l2->next;
		}
		else if (l2 == nullptr) {
			cur->val = l1->val;
			l1 = l1->next;
		}
		else {
			if (l1->val < l2->val) {
				cur->val = l1->val;
				l1 = l1->next;
			}
			else {
				cur->val = l2->val;
				l2 = l2->next;
			}
		}
		if (prev != nullptr)
			prev->next = cur;
		prev = cur;
		cur = new ListNode();
	}
	return head;
}

int main() {
	ListNode* l1 = new ListNode(1);
	ListNode* l2 = new ListNode(2);
	ListNode* l3 = new ListNode(4);
	l1->next = l2;
	l2->next = l3;
	printLinkedList(l1);

	ListNode* l4 = new ListNode(1);
	ListNode* l5 = new ListNode(3);
	ListNode* l6 = new ListNode(4);
	l4->next = l5;
	l5->next = l6;
	printLinkedList(l4);

	ListNode* l = mergeTwoLists(l1, l4);
	printLinkedList(l);

}
