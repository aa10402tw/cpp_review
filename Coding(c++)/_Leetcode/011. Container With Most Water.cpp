/* [Question Description]
Given n non-negative integers a1, a2, ..., an , where each represents a point at coordinate (i, ai). n vertical lines are drawn such that the two endpoints of the line i is at (i, ai) and (i, 0). Find two lines, which, together with the x-axis forms a container, such that the container contains the most water.
Notice that you may not slant the container.

# Example 1
Input: height = [1,8,6,2,5,4,8,3,7]
Output: 49
Explanation: The above vertical lines are represented by array [1,8,6,2,5,4,8,3,7]. In this case, the max area of water (blue section) the container can contain is 49.

# Example 2
Input: height = [1,1]
Output: 1

# Example 3
Input: height = [4,3,2,1,4]
Output: 16

# Example 4
Input: height = [1,2,1]
Output: 2
*/ 
#include <iostream>
#include <vector>
#include <algorithm>

/* Brute-Force Solution O(N^2) */
int maxArea(std::vector<int>& height) {
	int ans = 0;
	for (int i = 0; i < height.size() - 1; i++) {
		for (int j = i + 1; j < height.size(); j++)
			ans = std::max(ans, std::min(height[i], height[j]) * (j - i));
	}
	return ans;
}

/* faster Solution O(N) */
int maxArea(std::vector<int>& height) {
	int left = 0, right = height.size() - 1;
	int ans = 0;

	/* 
	area = width * height
	Start from max width, then decrease width and increase height to find greater area 
	*/
	while (left < right) {
		int area = (right - left) * std::min(height[left], height[right]);
		ans = std::max(ans, area);
		// Try to incrase the min height, because increase the max height is useless
		if (height[left] < height[right]) left += 1; 
		else right -= 1;
	}
	return ans;
}

int main() {

}
