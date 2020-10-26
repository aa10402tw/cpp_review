#include <iostream>
#include <string>
#include <vector>
#include <algorithm>


/* Solution 
Use topological sort (first run DFS, then sort the nodes by ending time, the lastest ending node start first) 
*/ 
struct Node {
	std::vector<int> dsts;
	int idx;
	int start;
	int color;
	int finish;
	Node(int idx) {
		this->idx = idx;
		start = -1;
		color = 0;
		finish = -1;
		dsts = std::vector<int>();
	}
};

int getTime() {
	static int time = 0;
	time += 1;
	return time;
}

bool DFS(std::vector<Node>& graph, int idx) {
	if (graph[idx].color == 2) return false;
	if (graph[idx].color == 1) return true;
	graph[idx].start = getTime();
	graph[idx].color = 1;
	for (int dst : graph[idx].dsts)
		if (DFS(graph, dst)) return true;
	graph[idx].color = 2;
	graph[idx].finish = getTime();
    return false;
}

static bool cmp(Node node1, Node node2) {
	return node1.finish > node2.finish;
}

std::vector<int> findOrder(int numCourses, std::vector<std::vector<int>>& prerequisites) {
	int N = numCourses;
	std::vector<Node> graph;
	for (int i = 0; i < N; i++)
		graph.push_back(Node(i));
	for (auto edge : prerequisites) {
		int src = edge[1], dst = edge[0];
		graph[src].dsts.push_back(dst);
	}
	for (int i = 0; i < N; i++)
		if (DFS(graph, i)) return {};
	std::sort(graph.begin(), graph.end(), cmp);
	std::vector<int> result;
	for (Node node : graph) {
		result.push_back(node.idx);
	}
	return result;
}
