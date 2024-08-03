//  https://leetcode.com/problems/implement-queue-using-stacks/submissions/1342584538/

#include <bits/stdc++.h>
using namespace std;
class MyQueue {
private:
    stack<int> stack1, stack2;
    void transferStack1ToStack2() {
        while (!stack1.empty()) {
            stack2.push(stack1.top());
            stack1.pop();
        }
    }

public:
    MyQueue() {}
    void push(int x) {
        stack1.push(x);
    }
    int pop() {
        if (stack2.empty()) {
            transferStack1ToStack2();
        }
        if (stack2.empty()) return -1;
        int frontElement = stack2.top();
        stack2.pop();
        return frontElement;
    }
    int peek() {
        if (stack2.empty()) {
            transferStack1ToStack2();
        }
        if (stack2.empty()) return -1;
        return stack2.top();
    }
    bool empty() {
        return stack1.empty() && stack2.empty();
    }
};

int main() {
    MyQueue* queue = new MyQueue();

    queue->push(1);
    queue->push(2);
    queue->push(3);

    cout << "Front element is: " << queue->peek() << endl; // Should print 1

    cout << "Popped element is: " << queue->pop() << endl; // Should print 1
    cout << "Popped element is: " << queue->pop() << endl; // Should print 2

    cout << "Front element is: " << queue->peek() << endl; // Should print 3

    queue->push(4);
    cout << "Front element is: " << queue->peek() << endl; // Should print 3

    cout << "Is queue empty? " << (queue->empty() ? "Yes" : "No") << endl; // Should print No

    queue->pop();
    queue->pop();
    
    cout << "Is queue empty? " << (queue->empty() ? "Yes" : "No") << endl; // Should print Yes

    delete queue;
    return 0;
}
