#include <iostream>
#include <vector>
using namespace std;

int party_rec(int n, vector<int>& dp)
{
    if (n <= 1)
        return 1;
    if (dp[n] != -1)
        return dp[n];

    dp[n] = (n - 1) * party_rec(n - 2, dp) + party_rec(n - 1, dp);

    return dp[n];
}

int party_itr(int n){

    vector<int> dp(n+1, 0);
    dp[0] = 1;
    dp[1] = 1;
    // dp[2] = 2;

    for(int i = 2; i <=n; i++) {
        dp[i] = dp[i-1] + (i-1) * dp[i-2];
    }

    return dp[n];
}

int main()
{
    int n;
    cin >> n;
    vector<int> dp(n + 1, -1);

    cout << party_rec(n, dp) << endl;

    cout << party_itr(n) << endl;

    return 0;
}