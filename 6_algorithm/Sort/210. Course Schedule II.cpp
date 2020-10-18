/* [Question Description]
There are a total of n courses you have to take labelled from 0 to n - 1.
Some courses may have prerequisites, for example, if prerequisites[i] = [ai, bi] this means you must take the course bi before the course ai.
Given the total number of courses numCourses and a list of the prerequisite pairs, return the ordering of courses you should take to finish all courses.
If there are many valid answers, return any of them. If it is impossible to finish all courses, return an empty array.

# Example 1
Input: numCourses = 2, prerequisites = [[1,0]]
Output: [0,1]
Explanation: There are a total of 2 courses to take. To take course 1 you should have finished course 0. So the correct course order is [0,1].

# Example 2
Input: numCourses = 4, prerequisites = [[1,0],[2,0],[3,1],[3,2]]
Output: [0,2,1,3]
Explanation: There are a total of 4 courses to take. To take course 3 you should have finished both courses 1 and 2. Both courses 1 and 2 should be taken after you finished course 0.
So one correct course order is [0,1,2,3]. Another correct ordering is [0,2,1,3].

# Example 3
Input: numCourses = 1, prerequisites = []
Output: [0]
*/ 
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
