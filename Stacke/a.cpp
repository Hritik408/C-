#include <iostream>
#include <stack> 
// find next smaller element on left side -> traverse from right

int main() {
        int arr[] = {6, 9, 14, 20, 7, 11, 16, 18, 10, 5};
        int n = sizeof(arr)/sizeof(arr[0]);
        std::stack<int> st;
        int ans[n];
        
        for(int i = 0; i < n; i++){
            ans[i] = -1;
        }

        for(int i = n-1; i >= 0; i--){

            if(st.empty()) st.push(i);

            else{
                while(!st.empty() && arr[i] < arr[st.top()]){   // next smaller on left side
                // while(!st.empty() && arr[i] > arr[st.top()]){  // next greater on left side
                    ans[st.top()] = arr[i];
                    st.pop();
                }
                st.push(i);
            }
        }

        for(int i = 0; i < n ; i++){
            std::cout << ans[i] << " ";
        }
    return 0;
}