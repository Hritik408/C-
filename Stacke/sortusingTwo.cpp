#include <iostream>
#include <stack>
#include <cstdlib>
#include <ctime>

int main()
{

    std::stack<int> s1, s2;
    std::srand(std::time(0)); // if u not take it then same sequence of no can generate

    for (int i = 0; i < 10; i++)
    {
        int random_val = std::rand() % 100; // generate random no btw 0 to 99
        s1.push(random_val);
    }

    while (!s1.empty())
    {
        int temp = s1.top();
        s1.pop();

        while (!s2.empty() && temp < s2.top())
        {
            int x = s2.top();
            s2.pop();   
            s1.push(x);
        }
        s2.push(temp);
    }

    while (!s2.empty())
    {
        int item = s2.top();
        s2.pop();
        s1.push(item);
    }

    while (!s1.empty())
    {
        std::cout << s1.top() << " ";
        s1.pop();
    }

    return 0;
}