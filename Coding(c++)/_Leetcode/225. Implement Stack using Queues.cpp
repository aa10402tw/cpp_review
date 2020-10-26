#include <iostream>
#include <queue>

/* STL : queue
push: ��ȥ[�����
pop: �����Y����
back: �^�ǧ��ڪ���
front: �^���Y����
size: �^�ǥثe����
empty: �^�ǬO�_����
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
