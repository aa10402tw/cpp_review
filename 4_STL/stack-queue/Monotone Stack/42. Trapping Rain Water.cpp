#include <iostream>
#include <vector>
#include <stack>

/* Solution based on two passes (from left then from right), time:O(N), extra space:O(1)
First passes (from 0 to N-1)
compute the water trapped if the current maximal building height is meet
(e.g., [2 0 1 3 0 1 2 1 4 2 1]  will compute the water between [2 -> 3] and [3 -> 4]
Second passes (from N-1 to leftHeightestPos)
compute the water trapped if the current maximal building height is meet
(e.g., [2 0 1 3 0 1 2 1 *4 2 1]  will compute the water between [4 <- 1] )
*/

typedef std::pair<int, int> IV;
int trap(std::vector<int>& height) {
	int N = height.size();
	if (N <= 1) return 0;
	int ans = 0;
	IV leftMax = std::make_pair(0, height[0]);
	for (int i = 1; i < N; i++) {
		if (height[i] >= leftMax.second) {
			int h = leftMax.second;
			for (int j = leftMax.first + 1; j < i; j++)
				ans += h - height[j];
			leftMax = std::make_pair(i, height[i]);
		}
	}
	IV rightMax = std::make_pair(N - 1, height[N - 1]);
	for (int i = N - 1; i >= leftMax.first; i--) {
		if (height[i] >= rightMax.second) {
			int h = rightMax.second;
			for (int j = rightMax.first - 1; j > i; j--)
				ans += h - height[j];
			rightMax = std::make_pair(i, height[i]);
		}
	}
	return ans;
}


/* Solution based on Monotonic Decreasing Stack, time:O(N), space:O(N) 
iterate over height, for height[i]
if stack is empty or height < stack.top(), push it into stack
while height > stack.top(), compute the water betwen height[i] and stack[top],
then push it into stack
*/
int trap(std::vector<int>& height) {
	int ans = 0;
	std::stack<int> S;
	int N = height.size();
	for (int i = 0; i < N; i++) {
		if (S.empty() || height[i] < height[S.top()]) {
			S.push(i);
		}
		else {
			while (!S.empty() && height[S.top()] < height[i]) {
				/* e.g., stack = [6,4,3], new element = 7
					at 3, width = 1 (pos(7)-pos(4)-1), height = 1 (min(4,6)-3)
					at 4, width = 2 (pos(7)-pos(5)-1), height = 2 (min(6,7)-4)
				*/
				int curh = height[S.top()];
				S.pop();
				if (!S.empty()) {
					int w = (i - S.top() - 1); // e.g., [4,3,5] 
					int h = std::min(height[i], height[S.top()]) - curh; // e.g., [4,3,5] height = 1 (min(4,5)-3)
					ans += w * h;
				}
			}
			S.push(i);
		}
	}
	return ans;
}

int main() {

}
