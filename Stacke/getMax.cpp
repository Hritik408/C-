#include <iostream>
#include <stack>
#include <climits>   // For INT_MIN

class MaxStack {
private:
    std::stack<int> s1; // Main stack
    std::stack<int> s2; // Stack to keep track of maximum values

public:
    MaxStack() {
        s2.push(INT_MIN); // Initialize the max stack with INT_MIN
    }

    void push(int x) {
        s1.push(x);
        int maxVal = std::max(x, s2.top());
        s2.push(maxVal);
    }

    void pop() {
        if (!s1.empty()) {
            s1.pop();
            s2.pop();
        } else {
            throw std::runtime_error("Stack is empty!");
        }
    }

    int top() {
        if (!s1.empty()) {
            return s1.top();
        } else {
            throw std::runtime_error("Stack is empty!");
        }
    }

    int getMax() {
        if (!s2.empty()) {
            return s2.top();
        } else {
            throw std::runtime_error("Stack is empty!");
        }
    }

    bool empty() const {
        return s1.empty();
    }

    size_t size() const {
        return s1.size();
    }
};

int main() {
    MaxStack stack;

    for (int i = 0; i < 10; i++) {
        stack.push(i);
        std::cout << "Pushed " << i << ", current max: " << stack.getMax() << std::endl;
    }

    while (!stack.empty()) {
        std::cout << "Popped " << stack.top() << ", current max: " << stack.getMax() << std::endl;
        stack.pop();
    }

    return 0;
}
