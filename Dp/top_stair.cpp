#include <iostream>
#include <vector>
using namespace std;

int stair(int n, vector<int>& dp ) {
    if(n <= 1) return 1;
    if(dp[n] != -1) return dp[n];

    dp[n] = stair(n-1, dp) + stair(n-2, dp);

    return dp[n];
   
}

int main() {
    int n;
    cin >> n;
     vector<int> dp(n+1, -1);
    cout << stair(n, dp) << endl;
    return 0;
}