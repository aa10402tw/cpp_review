#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <queue> 

struct ListNode {
	int val;
	ListNode* next;
	ListNode() : val(0), next(nullptr) {}
	ListNode(int x) : val(x), next(nullptr) {}
	ListNode(int x, ListNode* next) : val(x), next(next) {}
};

/* Naive Solution, Time: O(N*K) */
ListNode* mergeKLists(std::vector<ListNode*>& lists) {
	int N = lists.size();
	ListNode* head = nullptr;
	ListNode* prev = nullptr;
	while (true) {
		int idx = -1;
		int _min = INT_MAX;
		for (int i = 0; i < N; i++) {
			if (lists[i] != nullptr) {
				if (lists[i]->val < _min) {
					_min = lists[i]->val;
					idx = i;
				}
			}
		}
		if (idx == -1) break;
		if (head == nullptr) {
			head = lists[idx];
			prev = head;
		}
		else {
			prev->next = lists[idx];
			prev = lists[idx];
		}
		lists[idx] = lists[idx]->next;
	}
	return head;
}


/* Priority Queue, Time: O(log(N)*K) */
struct NodeCmp {
	bool operator()(ListNode* a, ListNode* b) {
		return a->val > b->val;
	}
};

ListNode* mergeKLists(std::vector<ListNode*>& lists) {
	ListNode* head = nullptr;
	ListNode* cur = nullptr;
	std::priority_queue< ListNode*, std::vector< ListNode*>, NodeCmp> Q;
	for (auto node : lists)
		if (node != nullptr) Q.push(node);

	while (!Q.empty()) {
		ListNode* p = Q.top();
		Q.pop();
		if (head == nullptr) head = p;
		else cur->next = p;
		cur = p;
		if (p->next != nullptr)
			Q.push(Q->next);
	}
	return head;
}

int main() {

}
