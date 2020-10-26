/* [Question Description]
Given head, the head of a linked list, determine if the linked list has a cycle in it.
There is a cycle in a linked list if there is some node in the list that can be reached again by continuously following the next pointer. Internally, pos is used to denote the index of the node that tail's next pointer is connected to. Note that pos is not passed as a parameter.
Return true if there is a cycle in the linked list. Otherwise, return false.
Follow up:
Can you solve it using O(1) (i.e. constant) memory?

# Example 1
Input: head = [3,2,0,-4], pos = 1
Output: true
Explanation: There is a cycle in the linked list, where the tail connects to the 1st node (0-indexed).

# Example 2
Input: head = [1,2], pos = 0
Output: true
Explanation: There is a cycle in the linked list, where the tail connects to the 0th node.

# Example 3
Input: head = [1], pos = -1
Output: false
Explanation: There is no cycle in the linked list.
*/ 
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
