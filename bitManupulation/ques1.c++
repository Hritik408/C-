#include <iostream>

int main(){
    int arr[] = {17,6,8,8,6,10,11,10};
    int xor_ = 0;
    int n = sizeof(arr)/sizeof(arr[0]);
    for(int i = 0; i < n; i++){
        xor_ ^= arr[i];
    }
  
  int pos;
  for(int i =0;i<=30;i++){
        if(xor_ & (1<<i)){
            pos = i;
            break;
        }
  }

  int xor_1 = 0;
  int xor_2 = 0;

  for(int i =0;i<n;i++){
    if(arr[i] & (1<<pos)){
        xor_1 ^= arr[i]; 
    }
    else{
        xor_2 ^= arr[i];
    }
  }

  std::cout << xor_1 << " " << xor_2 << std::endl;

  return 0;
}