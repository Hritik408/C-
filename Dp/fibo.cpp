#include <iostream>
#include <vector>
using namespace std;

int fibo(int n) {
    if(n <= 1) return n;

    vector<int> dp(n+1, 0);
    dp[0] = 0;
    dp[1] = 1;

    for(int i = 2; i <=n; i++){
        dp[i] = dp[i-1] + dp[i-2]; 
    }
    return dp[n];
}
 
 int fibo_rec(int n, vector<int>& dp){

    if(n <= 1) return n;

    if(dp[n] != -1) return dp[n];

    dp[n] = fibo_rec(n-1, dp) + fibo_rec(n-2, dp);

    return dp[n];
 }


int main() {
    int n;
    cin >> n;
    // vector<int> dp(n+1, -1);
    cout << "Iterative:" << fibo(n) << " ";
        vector<int> dp(n+1, -1);

    cout << "Recursive:" <<fibo_rec(n, dp) <<endl;
    return 0;

}
