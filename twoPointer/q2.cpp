#include <iostream>
#include <cmath>

int main()
{
    int arr[] = {-3, 0, 2, 3, 5, 9, 12};
    int n = sizeof(arr) / sizeof(arr[0]);
    int K = 5, p1 = 0, p2 = 1, count = 0;
    int k = std::abs(K);

    while (p1 < n && p2 < n)
    {
        int d = arr[p2] - arr[p1];
        if (d == k)
        {
            count++;
            p1++;
            p2++;
        }
        else if (d < k)
            p2++;
        else
        {
            p1++;
            if (p1 == p2)
                p2++;
        }
    }

    std::cout << count;

    return 0;
}