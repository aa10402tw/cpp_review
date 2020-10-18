/* [Question Description]
Write a program to find the node at which the intersection of two singly linked lists begins.
For example, the following two linked lists:
begin to intersect at node c1.

# Example 1
Input: intersectVal = 8, listA = [4,1,8,4,5], listB = [5,6,1,8,4,5], skipA = 2, skipB = 3
Output: Reference of the node with value = 8
Input Explanation: The intersected node's value is 8 (note that this must not be 0 if the two lists intersect). From the head of A, it reads as [4,1,8,4,5]. From the head of B, it reads as [5,6,1,8,4,5]. There are 2 nodes before the intersected node in A; There are 3 nodes before the intersected node in B.

# Example 2
Input: intersectVal = 2, listA = [1,9,1,2,4], listB = [3,2,4], skipA = 3, skipB = 1
Output: Reference of the node with value = 2
Input Explanation: The intersected node's value is 2 (note that this must not be 0 if the two lists intersect). From the head of A, it reads as [1,9,1,2,4]. From the head of B, it reads as [3,2,4]. There are 3 nodes before the intersected node in A; There are 1 node before the intersected node in B.

# Example 3
Input: intersectVal = 0, listA = [2,6,4], listB = [1,5], skipA = 3, skipB = 2
Output: null
Input Explanation: From the head of A, it reads as [2,6,4]. From the head of B, it reads as [1,5]. Since the two lists do not intersect, intersectVal must be 0, while skipA and skipB can be arbitrary values.
Explanation: The two lists do not intersect, so return null.
*/ 
#include <iostream>
#include <vector>
#include <unordered_map>

struct ListNode {
	int val;
	ListNode* next;
	ListNode(int x) : val(x), next(NULL) {}
};

/* Map Soulution time: O(N), space: O(N)*/
ListNode* getIntersectionNode(ListNode* headA, ListNode* headB) {
	std::unordered_map<ListNode*, int> ptrCnt;
	ListNode *ptrA=headA, *ptrB=headB;
	while (ptrA != nullptr || ptrB != nullptr) {
		if (ptrA != nullptr) {
			if (ptrCnt.find(ptrA) == ptrCnt.end())
				ptrCnt.insert(std::make_pair(ptrA, 1));
			else
				return ptrA;
			ptrA = ptrA->next;
		}
		if (ptrB != nullptr) {
			if (ptrCnt.find(ptrB) == ptrCnt.end())
				ptrCnt.insert(std::make_pair(ptrB, 1));
			else
				return ptrB;
			ptrB = ptrB->next;
		}
	}
	return nullptr;
}

int getListLen(ListNode* head) {
	int len = 0;
	while (head != nullptr) {
		head = head->next;
		len += 1;
	}
	return len;
}

/* First compute the length of two list, 
then move head of longer list to make the two list have same length, 
finally compare each node step by step*/
ListNode* getIntersectionNode(ListNode* headA, ListNode* headB) {

	/* Make two lists have same length*/
	int lenA = getListLen(headA);
	int lenB = getListLen(headB);
	int diff = lenA - lenB;
	if (diff > 0)
		for (int i = 0; i < diff; i++) headA = headA->next;
	else
		for (int i = 0; i < diff; i++) headB = headB->next;

	/* Compare each pair of node along the way */
	while (headA != nullptr && headB != nullptr) {
		if (headA == headB) return headA;
		headA = headA->next;
		headB = headB->next;
	}
	return nullptr;
}

int main() {

}
