#include <iostream>

int max_element(int arr[], int size){

int maxi = arr[0];  

    for (int i = 1; i < size; ++i) {
        if (arr[i] > maxi) {
            maxi = arr[i];  
        }
    }

    return maxi;
}

int sum(int arr[], int n){
     int sum = 0;
     for(int i = 0; i < n; i++){
        sum+=arr[i];
     }

     return sum;
}

bool isValid(int arr[], int n, int k, int mid){
    int sum = 0;
    int count = 1;

    for(int i = 0; i < n; i++){
        sum = sum + arr[i];
        if(sum > mid){
            count++;
            sum = arr[i];
        }
    }

    if(count <= k) return true;
    else return false;
}

int Ttime(int arr[], int n, int k){
    int start = max_element(arr, n);
    int end = sum(arr, n);
    int ans;
    
    while(start <= end){
        int mid = (start+end)/2;

        if(isValid(arr, n, k, mid)){
            ans = mid;
            end = mid-1;
        }
        else start = mid+1;
    }

    return ans;
}

int main(){
    int arr[] = {3, 5, 1, 7, 8, 2, 5, 3, 10, 1, 4, 7, 5, 4, 6};
    int n = sizeof(arr)/sizeof(arr[0]);
    int k = 5;
    int ans = Ttime(arr, n, k);
    std::cout << ans;

   return 0;
}