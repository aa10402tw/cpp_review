/* [Question Description]
Say you have an array for which the ith element is the price of a given stock on day i.
If you were only permitted to complete at most one transaction (i.e., buy one and sell one share of the stock), design an algorithm to find the maximum profit.

# Example 1
Input: [7,1,5,3,6,4]
Output: 5
Explanation: Buy on day 2 (price = 1) and sell on day 5 (price = 6), profit = 6-1 = 5.
             Not 7-1 = 6, as selling price needs to be larger than buying price.

# Example 2
Input: [7,6,4,3,1]
Output: 0
Explanation: In this case, no transaction is done, i.e. max profit = 0.
*/ 
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
