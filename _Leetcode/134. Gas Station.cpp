#include <iostream>
#include <vector>

int canCompleteCircuit(std::vector<int>& gas, std::vector<int>& cost) {

	/* Go from first station, if gas < 0, restart from next station*/
	int len = 0;
	int cur = 0;
	int startPos = 0;

	for (int i = 0; i < gas.size() * 2; i++) {
		int idx = i % gas.size();
		cur = cur + gas[idx] - cost[idx];
		if (cur < 0) {
			cur = 0;
			len = 0;
			startPos = (idx + 1) % gas.size(); // restart from next station
		}
		else {
			len += 1;
			if (len == gas.size()) return startPos;
		}
	}
	return -1;
}

int main() {

}
