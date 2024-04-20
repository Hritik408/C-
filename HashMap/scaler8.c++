#include <iostream>
#include <set>
// a[i] + a[j] = k

bool check(int arr[], int n, int k){

      std::set<int> x;

    for (int i = 0; i < n; i++)
    {    
        if (x.find(k - arr[i]) != x.end())  {    // Check if there is a pair with sum equal to k
            return true;
            break;
        }
        else x.insert(arr[i]);
    }

    return false;
} 

int main()
{
    int arr[] = {8, 9, 1, -2, 4, 5, 11, -6, 7, 5};
    int n = sizeof(arr) / sizeof(arr[0]);
    int k = 10;
    bool ans = check(arr, n, k);

    std::cout << (ans ? "true" : "false");

    return 0;
}