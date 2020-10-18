/* [Question Description]
Given the head of a linked list, remove the nth node from the end of the list and return its head.
Follow up: Could you do this in one pass?

# Example 1
Input: head = [1,2,3,4,5], n = 2
Output: [1,2,3,5]

# Example 2
Input: head = [1], n = 1
Output: []

# Example 3
Input: head = [1,2], n = 1
Output: [1]
*/ 
#include <iostream>
#include <string>

struct ListNode {
	int val;
	ListNode* next;
	ListNode() : val(0), next(nullptr) {}
	ListNode(int x) : val(x), next(nullptr) {}
	ListNode(int x, ListNode* next) : val(x), next(next) {}
	
};

int solve(ListNode* node, int n) {
	if (node->next == nullptr) // tail node
		return 1; // 1-th from back
	else {
		int Nth = solve(node->next, n) + 1;
		//std::cout << Nth << std::endl;
		if (n+1 == Nth) {
			node->next = node->next->next;
		}
		return Nth;
	}

}

ListNode* removeNthFromEnd(ListNode* head, int n) {
	if (head == nullptr || (head->next == nullptr && n == 1)) {
		return nullptr;
	}
	int Nth = solve(head, n);
	if (Nth == n)
		return head->next;
	return head;
}

void printList(ListNode* head) {
	ListNode* cur = head;
	while (cur != nullptr) {
		std::cout << cur->val;
		if (cur->next != nullptr)
			std::cout << "->";
		cur = cur->next;
	}
	std::cout << std::endl;
}

int main() {
	ListNode* l1 = new ListNode(1);
	ListNode* l2 = new ListNode(2);
	ListNode* l3 = new ListNode(3);
	ListNode* l4 = new ListNode(4);
	ListNode* l5 = new ListNode(5);
	l1->next = l2;
	l2->next = l3;
	l3->next = l4;
	l4->next = l5;
	printList(l1);

	l1 = removeNthFromEnd(l1, 2);
	printList(l1);
}
