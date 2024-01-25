#include<iostream>

int p(int n);

int main(){
    int n = 3;
    int result = p(n);
    std::cout << result << std::endl;
    return 0;
}
  int p(int n){   
    return 1<<n;
  }