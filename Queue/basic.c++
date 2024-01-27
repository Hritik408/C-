#include <iostream>
#include <queue>

int main() {
    // Declare a queue of integers
    std::queue<int> myQueue;

    // Insert elements into the queue using push()
    myQueue.push(10);
    myQueue.push(20);
    myQueue.push(30);

    // Display the elements in the queue
    std::cout << "Elements in the queue: ";
    while (!myQueue.empty()) {
        std::cout << myQueue.front() << " ";
        myQueue.pop(); // Remove the front element
    }

    return 0;
}

