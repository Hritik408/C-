#include <iostream>
#include <algorithm>  //  sort

int main(){
    int arr[] = {2,5,1,9,8,3};
    int n = sizeof(arr) / sizeof(arr[0]);
     std::sort(arr, arr + n);

    for(int i = 0; i< n ;i++){
        std::cout<< arr[i] << " ";
    }
} 