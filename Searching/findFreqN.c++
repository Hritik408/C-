#include <iostream>

int fir_occ(int arr[], int k, int n)
{
    int start = 0, end = n - 1;
    int first = -1;

    while (start <= end)
    {
        int mid = (start + end) / 2;
        if (arr[mid] == k)
        {
            first = mid;
            end = mid - 1;
        }
        else if (arr[mid] < k)
            start = mid + 1;
        else if (arr[mid] > k)
            end = mid - 1;
    }
    return first;
}

int last_occ(int arr[], int k, int n)
{
    int start = 0, end = n - 1;
    int last = -1;

    while (start <= end)
    {
        int mid = (start + end) / 2;

        if (arr[mid] == k)
        {
            last = mid;
            start = mid + 1;
        }
        else if (arr[mid] < k)
            start = mid + 1;
        else if (arr[mid] > k)
            end = mid - 1;
    }

    return last;
}

int main()
{
    int arr[] = {-3, -3, 0, 0, 0, 1, 1, 4, 4, 4, 4, 4, 8, 8, 10, 13, 13};

    int n = sizeof(arr) / sizeof(arr[0]);
    int k = 4;
    int first_occurence = fir_occ(arr, k, n);
    int last_occurence = last_occ(arr, k, n);

    int ans = last_occurence - first_occurence + 1;

    std::cout << ans << std::endl;

    return 0;
}
