#include <iostream>
#include <algorithm>

int main(){
    int arr[] = {2,5,3,1,7};
    int n = sizeof(arr)/sizeof(arr[0]);
    std::sort(arr, arr + n);
    for(int i =0;i<n;i++){
        std::cout << arr[i] << " ";
    }
    return 0;
}

