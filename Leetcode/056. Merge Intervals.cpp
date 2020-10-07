#include <iostream>
#include <vector>
#include <algorithm>

/* STL sort custom compator 

bool compareInterval(std::vector<int> i1, std::vector<int> i2) {
	return (i1[0] < i2[0]);
}

std::sort(intervals.begin(), intervals.end(), compareInterval);

*/

bool compareInterval(std::vector<int> i1, std::vector<int> i2) {
	return (i1[0] < i2[0]);
}

std::vector<std::vector<int>> merge(std::vector<std::vector<int>>& intervals) {
	if (intervals.size() <= 1) return intervals;
	std::sort(intervals.begin(), intervals.end(), compareInterval);
	std::vector<std::vector<int>> result;

	result.push_back(intervals[0]);
	int idx_new = 0;
	int idx_old = 1;
	while (idx_old < intervals.size()) {
		/** Merge if two interval overlaped */
		if (result[idx_new][1] >= intervals[idx_old][0]) {
			std::vector<int> interval_merge = { result[idx_new][0], std::max(result[idx_new][1], intervals[idx_old][1]) };
			result[idx_new] = interval_merge;
			idx_old += 1;
		}
		else {
			result.push_back(intervals[idx_old]);
			idx_old += 1;
			idx_new += 1;
		}
	}
}

int main() {

}
