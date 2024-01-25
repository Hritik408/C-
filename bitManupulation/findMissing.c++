#include <iostream>
int main(){
    int arr[] = {1,3,4,5};
    int n = sizeof(arr)/sizeof(arr[0]) + 1;
    std::cout << n << std::endl;
    int xor_ = 0;
    
    for(int i = 0; i < n-1; i++){
        xor_^=(i+1);
        xor_^=arr[i];
    }
      xor_^=n;

   std::cout << xor_ << std::endl;

    return 0;

}
      
