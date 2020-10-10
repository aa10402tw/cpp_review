#include <iostream>

struct ListNode {
	int val;
	ListNode* next;
	ListNode() : val(0), next(nullptr) {}
	ListNode(int x) : val(x), next(nullptr) {}
	ListNode(int x, ListNode* next) : val(x), next(next) {}
};

ListNode* swapPairs(ListNode* head) {
	if (head == nullptr || head->next == nullptr) return head;
	ListNode* nextNode = head->next;
	ListNode* nextNextNode = head->next->next;
	head->next = swapPairs(nextNextNode);
	nextNode->next = head;
	return nextNode;
}


int main() {

}
