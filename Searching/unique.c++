#include <iostream>
#include <climits>

int findUnique(int arr[], int n)
{

    if (n == 1)
        return arr[0];
    if (arr[0] != arr[1])
        return arr[0];
    if (arr[n - 1] != arr[n - 2])
        return arr[n - 1];

    int start = 0, end = n - 1;

    while (start <= end)
    {
        int mid = (start + end) / 2;

        if (arr[mid] != arr[mid - 1] && arr[mid] != arr[mid + 1])
            return arr[mid];

        if (arr[mid] == arr[mid - 1])  // not my first occ
            mid = mid - 1;  // make it first occ

        if (mid % 2 == 0)
            start = mid + 2;
        if (mid % 2 != 0)
            end = mid - 1;
    }
}

int main()
{
    int arr[] = {3, 3, 1, 1, 8, 8, 10, 10, 19, 6, 6, 2, 2, 4, 4};
    int n = sizeof(arr) / sizeof(arr[0]);
    int ans = findUnique(arr, n);

    std::cout << ans;

    return 0;
}