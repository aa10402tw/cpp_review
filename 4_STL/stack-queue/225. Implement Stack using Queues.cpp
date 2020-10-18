#include <iostream>
#include <queue>

/* STL : queue
push: 把值加到尾巴
pop: 移除頭的值
back: 回傳尾巴的值
front: 回傳頭的值
size: 回傳目前長度
empty: 回傳是否為空
*/

class MyStack {
public:
    /** Initialize your data structure here. */
    std::queue<int> q;
    MyStack() {
 
    }

    /** Push element x onto stack. */
    void push(int x) {
        q.push(x);
    }

    /** Removes the element on top of the stack and returns that element. */
    int pop() {
        int N = q.size();
        for (int i = 0; i < N; i++) {
            int x = q.front();
            q.pop();
            if (i == N - 1)
                return x;
            else
                q.push(x);
        }
    }

    /** Get the top element. */
    int top() {
        int N = q.size();
        for (int i = 0; i < N; i++) {
            int x = q.front();
            q.pop();
            q.push(x);
            if (i == N - 1)
                return x;
        }
    }

    /** Returns whether the stack is empty. */
    bool empty() {
        return q.empty();
    }
};

int main() {

}
