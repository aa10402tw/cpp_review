#include <iostream>

struct ListNode {
	int val;
	ListNode* next;
	ListNode(int x) : val(x), next(NULL) {}
};

/* Two pointer fast and slow, fast make two steps and slow make one step at a time, 
if there is a cycle, they must meet somewhile in the cycle 
(because fast is faster than slow, fast will chase over slow eventually)
e.g., a cycle  1 -> 2 -> 3 -> 4 -> 5 -> 1 
slow : (1, 2, 3, 4, 5),   1
fast : (1, 3, 5), (2, 4), 1
*/
bool hasCycle(ListNode* head) {
	ListNode* fast = head;
	ListNode* slow = head;
	while (fast != nullptr) {
		if (fast->next == nullptr) return false;
		fast = fast->next->next;
		slow = slow->next;
		if (slow == fast) return true;
	}
	return false;
}

int main() {

}
