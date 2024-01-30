#include <iostream>

int pow(int a, int n){
    if(n==0) return 1;
    int x = pow(a,n/2);
    if(n%2 == 0) {
        return x*x;
    }
    else {
        return a*x*x;
    }
}

int main(){
    int a = 2;
    int n = 3;
    int result = pow(a,n);
    std::cout<< result <<std::endl;
    return 0;
}