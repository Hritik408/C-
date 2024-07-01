#include <iostream>
 
int main() {
    int arr[] = {3, 5, 9, 11, 20, 22, 30};
    int n = sizeof(arr)/ sizeof(arr[0]);
    int k = 25;
    int p1 = 0, p2 = n-1;
    int count = 0;

    while(p1 <= p2){
        if(arr[p1] * arr[p2] < k){
            count += p2-p1+1;
            p1++;
        }
        else p2--;
    }
   std::cout << count;

}