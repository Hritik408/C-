#include <iostream>

void swap(int &a, int &b){
    int temp = a;
    a = b;
    b = temp;
}

int main()
{
    int arr[] = {3, 6, 1, 10, 8, 5};
    int n = sizeof(arr) / sizeof(arr[0]);

    for (int i = 0; i < n; i++)
    {
        int count = 0;
        for (int j = 0; j < n - 1 - i; j++) 
        {
            if (arr[j] > arr[j + 1])
            {
                swap(arr[j], arr[j + 1]);
                count++;
            }
        }
        if (count == 0)
            break;
    }

        std::cout << arr[n-3] << " ";  // here u can get element as u want
    

    return 0;
}