#include <iostream>
#include <cstdlib>
using namespace std;

 int reach(int arr[4][4], int n, int m){

    int dp[n][m];

    for(int i = 0; i < n; i++){
        if(arr[0][i] == 0)  dp[0][i] = 0;
        else if (i==0) dp[0][i] = 1; //starting point
        else  dp[0][i] = dp[0][i-1];
    }

    for(int j = 0; j < n; j++){
        if(arr[j][0] == 0)  dp[j][0] = 0;
        else if (j==0) dp[j][0] = 1;  // starting point is always one
        else  dp[j][0] = dp[j-1][0];
    }



    for(int i = 1; i < n; i++){
        for(int j = 1; j < m; j++){
            if(arr[i][j] == 0) dp[i][j] = 0;
            else dp[i][j] = dp[i-1][j] + dp[i][j-1];
        }
    }

    return dp[n-1][m-1];
 }

int main()
{

    int n = 4;
    int m = 4;
    int arr[4][4] = {
        {1, 2, 6, 9},
        {1, 0, 6, 0},
        {0, 2, 5, 1},
        {1, 1, 2, 3}};

    cout << "To reach (i, j) from (0,0): " << reach(arr, n, m) << endl;

    return 0;
}
