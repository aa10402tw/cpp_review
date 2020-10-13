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
