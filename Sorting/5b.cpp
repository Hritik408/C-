#include <iostream>

// int main() {
//     int arr[] = {10, 2, 3, 8, 7};
//     int n = sizeof(arr)/sizeof(arr[0]);
//     int p1 = 0, p2 = n-1, temp[n], i = 1;
//     while(i < n){
//       if(arr[i] > arr[0]) temp[p2--] = arr[i++];
//       else temp[p1++] = arr[i++];
//     }
//     temp[p2] = arr[0];
//     for(int i = 0; i < n; i++){
//         std::cout << temp[i] << " ";
//     }

//     return 0;   
// }

   void swap(int &a, int &b){
    int temp = a;
    a = b;
    b = temp;
   }

int main() {
    int arr[] = {10, 2, 3, 8, 7};
    int n = sizeof(arr)/sizeof(arr[0]);
    int p1 = 0, p2 = n-1;

    while(p1 <= p2){
      if(arr[p1] < arr[0]){
        p1++;
        continue;
      }
      else if(arr[p2] >= arr[0]){
        p2--;
        continue;
      }
      swap(arr[p1], arr[p2]);
      p1++;
      p2--;
    }

    swap(arr[0], arr[p1-1]);

    for(int i = 0; i < n; i++){
        std::cout << arr[i] << " ";
    }

    return 0;   
}
