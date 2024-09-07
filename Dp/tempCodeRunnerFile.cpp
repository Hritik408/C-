    #include <iostream>
    #include <cstdlib> 

    using namespace std;

    int reach(int n, int m) {
        int dp[n][m];

        for(int i = 0; i < n; i++){
            dp[0][i] = 1;
        }
        
        for(int j = 0; j < m; j++){
            dp[j][0] = 1;
        }

        for(int i = 0; i < n; i++){
            for(int j = 0; j < m; j++){
                dp[i][j] = dp[i-1][j] + dp[i][j-1];
            }
        }
        return dp[n-1][m-1];
    }

    int main() {

        int arr[5][5];

        for (int i = 0; i < 5; i++) {
            for (int j = 0; j < 5; j++) {
                arr[i][j] = rand() % 100; 
            }
        } 
        int n, m = 5;

        cout << "To reach (i, j) from (0,0)" << reach(n, m);


        return 0;
    }