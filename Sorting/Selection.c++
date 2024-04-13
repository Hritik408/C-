#include <iostream>
#include <iterator> // for size
#include <climits>

void swap(int &arr, int &srr)
{
    int temp = arr;
    arr = srr;
    srr = temp;
}

int main()
{
    int arr[] = {3, 6, 1, 19, 8, 7, 5};
    int n = sizeof(arr) / sizeof(arr[0]);

    for (int i = 0; i < n; i++)
    {
        int min_value = INT_MAX;
        int min_idx = -1;
        
        for (int j = i; j < n; j++)
        {
            if (arr[j] < min_value)
            {
                min_value = arr[j];
                min_idx = j;
            }
        }
        swap(arr[i], arr[min_idx]);
    }

    for (int i = 0; i < n; i++)
    {
        std::cout << arr[i] << " ";
    }

    return 0;
}
