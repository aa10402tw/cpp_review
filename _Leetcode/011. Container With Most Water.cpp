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
