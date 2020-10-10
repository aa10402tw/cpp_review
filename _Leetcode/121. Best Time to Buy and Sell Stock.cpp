#include <iostream>
#include <vector>

/* Idea: 
First compute the highest price after i-th day for all i,
then compute the max profit for each day and select the maximum of all day
*/
int maxProfit(std::vector<int>& prices) {
	if (prices.size() < 2) return 0;
	std::vector<int> highest_after(prices.size(), INT_MIN);
	for (int i = prices.size() - 2; i >= 0; i--) {
		highest_after[i] = std::max(highest_after[i + 1], prices[i + 1]);
	}
	int ans = 0;
	for (int i = 0; i < prices.size()-1; i++) {
		ans = std::max(ans, highest_after[i] - prices[i]);
	}
	return ans;
}

int main() {
	std::vector<int> prices = { 7, 1, 5, 3, 6, 4 };
	std::cout << maxProfit(prices) << std::endl;
}
