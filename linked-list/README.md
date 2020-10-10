Table of Contents
=================
  * [Basic-Struct](#Basic-Struct)
  * [Traversal](#Traversal)

## Basic-Struct
```
struct ListNode {
	int val;        // value of this node
	ListNode* next; // point to the next node
	ListNode(int x) : val(x), next(NULL) {}
};
```

## Traversal
```
/* Convect List to vector, time: O(N), extra space: O(N) */
std::vector<int> ListToVec(ListNode* head) {
	std::vector<int> vec;
	while (head != nullptr) {
		vec.push_back(head->val);
		head = head->next;
	}
	return vec;
}
```
