#include <iostream>
#include <stack>

int getMax(int arr[], int n)
{
    std::stack<int> s;
    int max_area = 0;
    int top_area = 0;

    int i = 0;
    while (i < n)
    {
        if (s.empty() || arr[i] >= arr[s.top()])
        {
            s.push(i++); // every push we goes right of elmenents
        }
        else
        {
            int tp = s.top();
            s.pop();
            top_area = arr[tp] * (s.empty() ? i : i - s.top() - 1);

            if (top_area > max_area)
                max_area = top_area;
        }
    }

    while (!s.empty())
    {
        int tp = s.top();
        s.pop();
        top_area = arr[tp] * (s.empty() ? i : i - s.top() - 1);

        if (top_area > max_area)
            max_area = top_area;
    }

    return max_area;
}

int main()
{
    int arr[] = {3, 5, 6, 4, 3, 5};
    int n = sizeof(arr) / sizeof(arr[0]);
    std::cout << "Maximum area is " << getMax(arr, n) << std::endl;

    return 0;
}