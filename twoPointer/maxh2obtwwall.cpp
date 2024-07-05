#include <iostream>
#include <algorithm>

int sol(int arr[], int n){
    int p1 = 0, p2 = n-1;
    int ans  = 0;

    while(p1 < p2){
        if(arr[p2] < arr[p1]){
            int area = (p2-p1) * arr[p2];
            ans = std::max(area, ans);
            p2--;
        }
        else if(arr[p1] < arr[p2]){
            int area = (p2-p1) * arr[p1];
            ans = std::max(area, ans);
            p1++;
        }
        else {   // arr[p1] == arr[p2]
          int area = (p2-p1) * arr[p1];
          ans = std::max(area, ans);
          p1++;
        }
    }

    return ans;
}

int main() {
    int arr[] = {3,5,4,7,3,6,5,4,1,2};
    int n = sizeof(arr)/sizeof(arr[0]);
    std::cout << sol(arr, n) ;
    return 0;
}