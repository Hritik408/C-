#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int maxi(int arr[], int n){
    vector<int> dp(n);
    dp[0] = arr[0];

    if (n > 1) {
        dp[1] = max(arr[0], arr[1]);
    }

    for (int i = 2; i < n; i++) {
        dp[i] = max(dp[i-1], arr[i] + max(dp[i-2], 0));
    }

    for (int i = 0; i < n; i++) {
        cout << dp[i] << " ";
    }
    cout << endl;

    return dp[n-1]; 
}

int main() {
    
    int arr[2][7] = {
        {3, 6, 4, 3, 4, 8, 7},
        {5, 7, 2, 9, 3, 9, 10}
    };

    int nrr[7];

    for (int j = 0; j < 7; j++) {
        nrr[j] = max(arr[0][j], arr[1][j]);
    }

    int n = 7;

    cout << "Maxi function result: " << maxi(nrr, n) << endl;

    return 0;
}
