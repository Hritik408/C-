#include <iostream>
#include <vector>
#include <limits>
#include <algorithm>
using namespace std;

int maxi(int arr[], int n){
    vector<int> dp(n);
    dp[0] = arr[0];

     if (n > 1) {
        dp[1] = max(arr[0], arr[1]);
    }

    for(int i = 2; i < n; i++) {
      dp[i] = max(dp[i-1], arr[i] + max(dp[i-2], 0));
    }

    for(int i = 0; i < n; i++){
      cout << dp[i] << " ";
    }

    cout << endl;

        return dp[n-1]; 

}

int main() {
    int arr[] = {9, 4, 13, 24};
    int n = sizeof(arr)/sizeof(arr[0]);
 
    cout << "Maximum subarray sum without adjacent elements: " << maxi(arr, n) << endl;

    return 0;
}