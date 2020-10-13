#include <iostream>
#include <vector>

struct ListNode {
	int val;
	ListNode* next;
	ListNode(int x) : val(x), next(NULL) {}
};

void deleteNode(ListNode* node) {
	ListNode* next = node->next;
	node->val = next->val;
	node->next = next->next;
	delete next;
}


int main() {

}
