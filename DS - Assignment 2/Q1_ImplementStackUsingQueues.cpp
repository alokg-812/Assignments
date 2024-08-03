// https://leetcode.com/problems/implement-stack-using-queues/submissions/1342569805/
#include <bits/stdc++.h>
using namespace std;

class MyStack {
private:
    queue<int> q1, q2;

public:
    MyStack() {}
    void push(int x) {
        q2.push(x);
        while (!q1.empty()) {
            q2.push(q1.front());
            q1.pop();
        }
        swap(q1, q2);
    }

    int pop() {
        if (q1.empty()) return -1;
        int topElement = q1.front();
        q1.pop();
        return topElement;
    }

    int top() {
        if (q1.empty()) return -1;
        return q1.front();
    }

    bool empty() {
        return q1.empty();
    }
};

int main() {
    MyStack* stack = new MyStack();
    stack->push(1);
    stack->push(2);
    stack->push(3);
    cout << "Top element is: " << stack->top() << endl; 
    cout << "Popped element is: " << stack->pop() << endl;
    cout << "Popped element is: " << stack->pop() << endl;
    cout << "Top element is: " << stack->top() << endl; 
    stack->push(4);
    cout << "Top element is: " << stack->top() << endl; 
    cout << "Is stack empty? " << (stack->empty() ? "Yes" : "No") << endl;
    stack->pop();
    stack->pop();    
    cout << "Is stack empty? " << (stack->empty() ? "Yes" : "No") << endl; 
    delete stack;
}
