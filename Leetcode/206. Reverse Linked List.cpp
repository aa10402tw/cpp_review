#include <iostream>
#include <string>
#include <unordered_map>

struct ListNode {
	int val;
	ListNode* next;
	ListNode() : val(0), next(nullptr) {}
	ListNode(int x) : val(x), next(nullptr) {}
	ListNode(int x, ListNode* next) : val(x), next(next) {}
};

/* Recursive version */
ListNode* helper(ListNode* prev, ListNode* cur) {
	ListNode* next = cur->next;
	cur->next = prev;
	if (next == nullptr) {
		return cur;
	}
	ListNode* head = helper(cur, next);
	return head;
}
ListNode* reverseList(ListNode* head) {
	if (head == nullptr) return nullptr;
	return helper(nullptr, head);
}

/* Iterative version */
ListNode* reverseList(ListNode* head) {
	if (head == nullptr) return nullptr;
	if (head->next == nullptr) return head;
	ListNode* prev = nullptr;
	ListNode* cur = head;
	ListNode* next = head->next;
	while (true) {
		if (next == nullptr) {
			cur->next = prev;
			return cur;
		}
		cur->next = prev;
		prev = cur;
		cur = next;
		next = next->next;
	}
}

int main() {

}
