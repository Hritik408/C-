#include <iostream>

int count2(int num){
    int count = 0;
    while (num) 
    {
        num = num & (num-1);
        count++;
    }
    return count;
}

int count(int num){
    int count = 0;
    while(num){   // this while loop iterate until the binary number is finished
        count += num & 1;  // if set bit found then add to count 
        num >>= 1;      // here each bit proceed to one right
    }
    return count;
}

int main(){
    int n;
    scanf("%d",&n);

  //  int result = count(n);
    int result = count2(n);

    std::cout << result <<std::endl;

    return 0;
    
}

