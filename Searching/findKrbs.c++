#include <iostream>
#include <climits>

int findUnique(int arr[], int n)
{
    int start = 0, end = n - 1;
    int k = n;
    while (start <= end)
    {
        int mid = (start + end) / 2;

        if (arr[mid] >= arr[0])
            start = mid + 1;
        if (arr[mid] < arr[0])
        {
            k = mid;
            end = mid - 1;
        }
    }

    return k;
}

int main()
{
    int arr[] = {5, 8, 10, 14, 18, 23, -15, -9, -6, 0, 2};
    int n = sizeof(arr) / sizeof(arr[0]);
    int ans = findUnique(arr, n);

    std::cout << ans;

    return 0;
}