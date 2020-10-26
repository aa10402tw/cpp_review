/* [Question Description]
Remove all elements from a linked list of integers that have value val.

# Example 1
Input:  1->2->6->3->4->5->6, val = 6
Output: 1->2->3->4->5
*/ 
#include <iostream>

struct ListNode {
	int val;
	ListNode* next;
	ListNode() : val(0), next(nullptr) {}
	ListNode(int x) : val(x), next(nullptr) {}
	ListNode(int x, ListNode* next) : val(x), next(next) {}
};

ListNode* removeElements(ListNode* head, int val) {
	if (head == nullptr) return nullptr;
	while (head->val == val) {
		head = head->next;
		if (head == nullptr) return nullptr;
	}
	head->next = removeElements(head->next, val);
	return head;
}

int main() {

}
