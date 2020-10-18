/* [Question Description]
Given a linked list, swap every two adjacent nodes and return its head.
You may not modify the values in the list's nodes. Only nodes itself may be changed.

# Example 1
Input: head = [1,2,3,4]
Output: [2,1,4,3]

# Example 2
Input: head = []
Output: []

# Example 3
Input: head = [1]
Output: [1]
*/ 
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
