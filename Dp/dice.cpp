#include <iostream>
#include <vector>
using namespace std;

int dice(int n)
{

    vector<int> dp(n + 1, 0);
    dp[0] = 1; // there is no way to get sum of zero(not rolling any dice)
    
    for(int i = 1; i <= n; i++){
        for(int face = 1; face <= 6; face++){
            if(face <= i){
                dp[i] += dp[i-face];
            }
        }
    }
   

    return dp[n];
}

int main()
{
    int n;
    cin >> n;
    cout << dice(n) << endl;
    return 0;
}

