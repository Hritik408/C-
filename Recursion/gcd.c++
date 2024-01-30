#include <iostream>

int gcd(int a, int b){
    if(b==0) return a;
    return gcd(b, a%b);
}

int main(){
    int a = 150;
    int b = 120;
    int result = gcd(a,b);
    std::cout<< result << std::endl;
    return 0;
}