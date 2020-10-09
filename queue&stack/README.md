Table of Contents
=================
  * [Queue](#Queue)
  * [Stack](#Stack)
  * [Priority-Queue](#Priority-Queue)

## Queue

## Stack

## Priority-Queue
Declare 
```
// std::priority_queue<T> pq; 
std::priority_queue<int> Q; // Default top is largest
int numbers[10] = {3, 6, 5, 555, 211, 321, 48, 99, 6773, 4};
for(int i=0; i<10; i++){
  Q.push(numbers[i]);
}

// std::priority_queue<T, std::vector<T>, cmp> pq; 
struct NodeCmp {
	bool operator()(ListNode* a, ListNode* b) {
		return a->val > b->val;
	}
}; 
std::priority_queue<ListNode*, std::vector<ListNode*>, NodeCmp> Q; // Top is smallest
for (ListNode* node : lists)
		if (node != nullptr) Q.push(node);

```
