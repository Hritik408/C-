#include <iostream>

bool result(int n, int i) {
      return ((n >> i) & 1) != 0;  // Return true if non-zero, false if zero
 //   return (n & (1<<i)) != 0; 
}

int main() {
  
  int n;
  printf("Enter the number: ");
  scanf("%d",&n);

  int idx;
  printf("Enter the binary index where u want to check set bit or not: ");
  scanf("%d",&idx);

    bool resultValue = result(n, idx);

    // Explicitly print "true" or "false"
      std::cout << "Result: " << std::boolalpha << resultValue << std::endl;

    return 0;
}