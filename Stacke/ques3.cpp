#include <iostream>
#include <stack>

int main()
{
    int arr[] = {6, 9, 14, 20, 7, 11, 16, 18, 10, 5};
    int n = sizeof(arr) / sizeof(arr[0]);
    std::stack<int> st;
    int ans[n];

    // initilize ans array to -1 means no smaller element found
    for (int i = 0; i < n; i++)
    {
        ans[i] = -1;
    }

    for (int i = 0; i < n; i++)
    {
        if (st.empty())
        {
            st.push(i); // push the index
        }
        else
        {
            // while (!st.empty() && arr[i] < arr[st.top()]) { // next smaller on right side
            while (!st.empty() && arr[i] > arr[st.top()]) {  // next larger on right side
                ans[st.top()] = arr[i];
                st.pop();
            }
            st.push(i);
        }
    }

    for (int i = 0; i < n; i++)
    {
        std::cout << ans[i] << " ";
    }

    return 0;
}