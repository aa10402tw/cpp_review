/* [Question Description]
Design a stack that supports push, pop, top, and retrieving the minimum element in constant time.

# Example 1
Input
["MinStack","push","push","push","getMin","pop","top","getMin"]
[[],[-2],[0],[-3],[],[],[],[]]

Output
[null,null,null,null,-3,null,0,-2]

Explanation
MinStack minStack = new MinStack();
minStack.push(-2);
minStack.push(0);
minStack.push(-3);
minStack.getMin(); // return -3
minStack.pop();
minStack.top();    // return 0
minStack.getMin(); // return -2
*/ 
#include <iostream>
#include <vector>

class MinStack {
public:
    std::vector<int> data;
    std::vector<int> mins;
    int N;
    /** initialize your data structure here. */
    MinStack() {
        data.clear();
        N = 0;
    }

    void push(int x) {
        if (N >= data.size())
            data.push_back(x);
        else
            data[N] = x;
        
        if (N >= mins.size()) {
            if (mins.size() >= 1)
                mins.push_back(std::min(mins[N - 1], x));
            else
                mins.push_back(x);
        }
        else {
            if (mins.size() >= 1)
                mins[N] = std::min(mins[N - 1], x);
            else
                mins[N] = x;
        }
           
        this->N += 1;
    }

    void pop() {
        N -= 1;
    }

    int top() {
        return data[N - 1];
    }

    int getMin() {
        return mins[N-1];
    }
};

int main() {

}
