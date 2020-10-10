#include <iostream>
#include <vector>

/* Idea: 
sell stock as long as profit > 0
*/
int maxProfit(std::vector<int>& prices) {
    int profit = 0, i, n = prices.size();
    for (i = 1; i < n; i++) {
        if (prices[i] > prices[i - 1])
            profit += prices[i] - prices[i - 1];
    }
    return profit;
}

int main() {
	std::vector<int> prices = { 7,1,5,3,6,4 };
	std::cout << maxProfit(prices) << std::endl;
}
