#include <iostream>
#include <unordered_set>
// count no of distinct element.

int main(){
    int arr[] = {2,3,2,5,7,5,9};
    int n = sizeof(arr)/sizeof(arr[0]);

    std::unordered_set<int> x;
    
    for(int i=0; i<n; i++){
        x.insert(arr[i]);
    }
    std::cout<< x.size();
}