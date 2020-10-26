/* [Question Description]
Given a singly linked list, determine if it is a palindrome.
Follow up:
Could you do it in O(n) time and O(1) space?

# Example 1
Input: 1->2
Output: false

# Example 2
Input: 1->2->2->1
Output: true
*/ 
#include <iostream>
#include <vector>

struct ListNode {
	int val;
	ListNode* next;
	ListNode() : val(0), next(nullptr) {}
	ListNode(int x) : val(x), next(nullptr) {}
	ListNode(int x, ListNode* next) : val(x), next(next) {}
};


/* Convect List to vector, time: O(N), extra space: O(N) */
std::vector<int> ListToVec(ListNode* head) {
	std::vector<int> vec;
	while (head != nullptr) {
		vec.push_back(head->val);
		head = head->next;
	}
	return vec;
}

bool isPalindrome(ListNode* head) {
	std::vector<int> vec = ListToVec(head);
	for (int i = 0; i < vec.size() / 2; i++) {
		if (vec[i] != vec[vec.size() - 1 - i]) return false;
	}
	return true;
}

/* Another approach: reverse the second part of list, time: O(N), space: O(N) */

int main() {

}
