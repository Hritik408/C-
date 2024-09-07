#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int long_ss(int arr[], int n){
     vector<int> dp(n);

     dp[0] = 1;
     int ans = 1;  // mimimum subseq lenth is one;

     for(int i = 1; i < n; i++) {
        dp[i] = 0;
        for(int j = 0; j < i; j++){
            if(arr[j] <= arr[i]){
                dp[i] = max(dp[i], dp[j]);
            }
        }
        dp[i] += 1;
        ans = max(dp[i], ans);
     }

     vector<int> sub_seq;
     int i = n-1;
     int curr_ans = ans;


      while (i >= 0)
      {
        if(dp[i] == curr_ans){
            sub_seq.push_back(arr[i]);
            curr_ans--;
        }
        i--;
      }

      reverse(sub_seq.begin(), sub_seq.end());
      
      for(int item : sub_seq){
        cout << item << " ";
      }
      
     cout << endl;

      return ans;

}

int main() {
    int arr[] = {10, 3, 12, 7, 2, 9, 11, 20, 11, 13, 6, 8};
    // int arr[] = {10, 3, 12, 7, 2, 9, 11, 20, 11, 13, 6, 8, 14, 2, 15, 9, 20};
    int n = sizeof(arr)/ sizeof(arr[0]);

    cout << "Longest increasing subsequence: " << long_ss(arr, n);

    return 0;
}