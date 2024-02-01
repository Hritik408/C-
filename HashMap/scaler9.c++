#include <iostream>
#include <set>
// subarray sum = k 

int main()
{
    int arr[] = {3, 2, 5, -7, 3, 3, 9, 2, -6};
    int n = sizeof(arr) / sizeof(arr[0]);
    int k = 18;

    int prefix_sum = 0;
    std::set<int> x;
    bool subarrayExists = false;
    x.insert(0);

        for (int i = 0; i < n; i++) {
        prefix_sum += arr[i];  // Initial entry for subarrays starting from the beginning
               
         // Check if there is a subarray with sum equal to k
        if (x.find(prefix_sum - k) != x.end())
        {
            subarrayExists = true;
            break;
        }
        else  x.insert(prefix_sum);
    }

    if (subarrayExists)   std::cout << "true";
    else  std::cout << "false";
    
    return 0;
}