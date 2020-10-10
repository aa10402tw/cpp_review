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
