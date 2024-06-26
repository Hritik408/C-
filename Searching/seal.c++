#include <iostream>
#include <climits>

int bs(int arr[], int n, int k)
{
    int start = 0, end = n - 1;
    int ans = INT_MIN;
    while (start <= end)
    {
        int mid = (start + end) / 2;
        if (arr[mid] >= k)
        {
            ans = arr[mid];
            end = mid - 1;
        }
        if (arr[mid] < k)
        {
            start = mid + 1;
        }
    }
    return ans;
}

int main()
{
    int arr[] = {2, 5, 9, 16, 27, 30, 35};
    int n = sizeof(arr) / sizeof(arr[0]);
    int k = 20;
    int ans = bs(arr, n, k);

    std::cout << ans;

    return 0;
}