#include <iostream>
#include <unordered_map>
#include <vector>
// cal no of sub[] whose sum=0

int main()
{
    //  int arr[] = {3, 2, 2, -1, -2, 3, -4, 3, -1, 3, -2, 1, 3};
    int arr[] = {2, 3, -3, 3};
    //  int arr[] = {3,2,2,-1,-2,3,-2,-2,3,1,-2,2,-2,2,-4,4,-1,0};
    int n = sizeof(arr) / sizeof(arr[0]);
    
    std::unordered_map<int, std::vector<int>> x;
    int prefix_sum = 0;
    int count = 0;
    x[0].push_back(-1);

    for (int i = 0; i < n; i++)
    {
        prefix_sum += arr[i];
        if (x.find(prefix_sum) != x.end()) // if there is dublicate present
        {
            count += x[prefix_sum].size(); // If duplicate present, update count by the size of the vector

        }
        x[prefix_sum].push_back(i); // Update the map with the current cumulative sum and index
    }

    std::cout << count;

    return 0;
}
