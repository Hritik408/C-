#include <iostream>
#include <set>
// subarray sum = k.

bool check(int arr[], int n, int k){

    std::set<int> x;
     int prefix_sum = 0;

    //    x.insert(0);

        for (int i = 0; i < n; i++) {
        prefix_sum += arr[i];  // Initial entry for subarrays starting from the beginning
               
         // Check if there is a subarray with sum equal to k
        if (x.find(prefix_sum - k) != x.end())
        {
            return true;
            break;
        }
        else  x.insert(prefix_sum);
    }

    return false;
}

int main()
{
    int arr[] = {3, 2, 5, -7, 3, 3, 9, 2, -6};
    int n = sizeof(arr) / sizeof(arr[0]);
    int k = 18;

    bool ans = check(arr, n, k);

    std::cout << (ans ? "true" : "false");
    
    return 0;
}