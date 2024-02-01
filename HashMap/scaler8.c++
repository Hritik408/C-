#include <iostream>
#include <set>
// a[i] + a[j] = k

int main()
{
    int arr[] = {8, 9, 1, -2, 4, 5, 111, -6, 7, 5};
    int n = sizeof(arr) / sizeof(arr[0]);
    std::set<int> x;
    int k = 10;
    for (int i = 0; i < n; i++)
    {     // Check if there is a pair with sum equal to k
        if (x.find(k - arr[i]) != x.end())  {
            std::cout << "true";
            break;
        }
        else x.insert(arr[i]);
    }

    return 0;
}