/* [Question Description]
There are a total of numCourses courses you have to take, labeled from 0 to numCourses-1.
Some courses may have prerequisites, for example to take course 0 you have to first take course 1, which is expressed as a pair: [0,1]
Given the total number of courses and a list of prerequisite pairs, is it possible for you to finish all courses?

# Example 1
Input: numCourses = 2, prerequisites = [[1,0]]
Output: true
Explanation: There are a total of 2 courses to take. 
             To take course 1 you should have finished course 0. So it is possible.

# Example 2
Input: numCourses = 2, prerequisites = [[1,0],[0,1]]
Output: false
Explanation: There are a total of 2 courses to take. 
             To take course 1 you should have finished course 0, and to take course 0 you should
             also have finished course 1. So it is impossible.
*/ 
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>


/* Solution 
Use DFS to check if cycle exist
*/ 
struct Node {
	std::vector<int> dsts;
	Node() { dsts = std::vector<int>(); }
};

bool DFS(std::vector<Node>& nodes, std::vector<int>& colors, int idx) {
	if (colors[idx] == 2) return false; // visited and finished
	if (colors[idx] == 1) return true; // visited and not finished -> cycle
	colors[idx] = 1;
	for (int dst : nodes[idx].dsts) {
		if (DFS(nodes, colors, dst)) return true;
	}
	colors[idx] = 2;
	return false;
}

bool hasCycle(std::vector<Node>& nodes) {
	int N = nodes.size();
	std::vector<int> colors(N, 0);
	for (int i = 0; i < N; i++)
		if (DFS(nodes, colors, i)) return true;
	return false;
}

bool canFinish(int numCourses, std::vector<std::vector<int>>& prerequisites) {
	int N = numCourses;
	std::vector<Node> nodes(N, Node());
	for (auto edge : prerequisites) {
		int src = edge[0], dst = edge[1];
		nodes[src].dsts.push_back(dst);
	}
    /* Print graph */
    for (int i=0; i<nodes.size(); i++) {
        std::cout << "Node " << i << ": ";
        for (int dst:nodes[i].dsts)
            std::cout << dst <<" ";
        std::cout << endl;
    }
	return !hasCycle(nodes);
}   
