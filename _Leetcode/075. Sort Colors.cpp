#include <iostream>
#include <vector>
#include <string>
#include <unordered_map>
#include <algorithm>


/* use counting sort -> time: O(N + k), extra space: O(K) 
input : [2,2,2,1,1,0]
counts : [1,2,3]
starts : [0,1,3]
output : [0,1,1,2,2,2]
*/
std::vector<int> countingSort(std::vector<int>& nums, int K) {
	int N = nums.size();

	/* compute the frquency of occurance for each number*/
	std::vector<int> counts(K, 0);
	for (int num : nums)
		counts[num] += 1;

	/* compute the starting positon of each number */
	std::vector<int> starts(K, 0);
	for (int i = 0; i < K; i++) {
		if (i == 0) starts[i] = 0;
		else starts[i] = starts[i - 1] + counts[i - 1];
	}

	/* Fill numbers counts[number] times in correct position*/
	std::vector<int> result(N, 0);
	for (int num : nums) {
		int idx = starts[num] + counts[num] - 1;
		counts[num] -= 1;
		result[idx] = num;
	}
	return result;
}

/* use selection sort -> time: O(N^2), extra space: O(1)
*/
void selectionSort(std::vector<int>& nums) {
	int N = nums.size();
	for (int i = 0; i < N-1; i++) {
		int min_idx = i;
		int cur_min = nums[i];
		for (int j = i+1; j < N; j++) {
			if (nums[j] < cur_min) {
				cur_min = nums[j];
				min_idx = j;
			}
		}
		std::swap(nums[i], nums[min_idx]);
	}
}

void sortColors(std::vector<int>& nums) {
	if (nums.size() <= 1) return;
	selectionSort(nums);
	//nums = countingSort(nums, 3); // Number (color) only have three choices 
}

int main() {

}
