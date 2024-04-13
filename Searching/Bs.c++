#include <iostream>

int bs(int arr[], int n, int k){
    int start = 0, end = n-1;
    while(start <= end){
        int mid = (start+end)/2;
        if(arr[mid] == k) return mid;
        if(arr[mid] < k) start = mid+1;
        else end = mid-1;
    }
    return -1;
}

int main(){
    int arr[] = {2,3,4,6,7,9,10};
    int n = sizeof(arr)/sizeof(arr[0]);
    int k = 92;
    int ans = bs(arr, n, k);
    if(ans != -1){
        std::cout << ans << std::endl;
    }
    else
    std::cout << "given element is not found" <<  std::endl;

    return 0;
}