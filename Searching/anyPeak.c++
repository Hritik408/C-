#include <iostream>
#include <climits>
// doubt hai abhi isme

int bs(int arr[], int n)
{

     if (n == 1)   return arr[0];
     if(arr[0] > arr[1]) return arr[0];
     if(arr[n-1] > arr[n-2]) return arr[n-1];
     
    int start = 1, end = n - 2;

    while (start <= end)
    {
        int mid = (start + end) / 2;

        if (arr[mid] > arr[mid - 1] && arr[mid] > arr[mid + 1])
        {
            return arr[mid];
        }
        else if (arr[mid - 1] > arr[mid])
        {
            end = mid - 1;
        }
        else if (arr[mid + 1] > arr[mid])
        {
            start = mid + 1;
        }
    }
    // return INT_MIN;
}

int main()
{
    int arr[] = {3, 2, 24, 25, 7, 4, 8};
    int n = sizeof(arr) / sizeof(arr[0]);
    int ans = bs(arr, n);
    std::cout << ans;

    return 0;
}