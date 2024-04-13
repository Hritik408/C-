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

    for (int i = 0; i < n-1; i++)
    {
     int j = i;
     while(j >=0 && arr[j] > arr[j+1]){
        swap(arr[j], arr[j+1]);
        j--;
     }  
    }

    for (int i = 0; i < n; i++)
    {
        std::cout << arr[i] << " ";
    }

    return 0;
}