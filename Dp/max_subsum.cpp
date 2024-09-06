#include <iostream>
#include <vector>
#include <limits>
#include <algorithm>
using namespace std;

void maxi(int arr[], int n) {

    vector<int> dp(n,0);

    dp[0] = arr[0];
    // int ans = arr[0];

    for(int i = 1; i < n; i++){
        dp[i] = max(dp[i-1] + arr[i], arr[i]);
        // ans = max(dp[i], ans);
    }

    // int maxsum = dp[0]; 
    for(int i = 0; i < n; i++) {
        // maxsum = max(maxsum, dp[i]);
        cout << dp[i] << " ";
    }
    // return ans;
    // return maxsum;
}

int main() {
    int arr[] = {3, -1, 8, -12, 10, -4, 3, 9, -2, 8, -40, 7};
    int n = sizeof(arr)/sizeof(arr[0]);

    // cout << "Maximum subArrray sum is " << maxi(arr, n) << endl;
    maxi(arr, n);

    return 0;
}