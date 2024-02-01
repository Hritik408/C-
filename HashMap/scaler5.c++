#include <iostream>
#include <set>

int main(){
    int arr[] = {3,2,2,-1,-1,-2,3,-4,3,-1,3,-2,1,3};
    int n = sizeof(arr)/sizeof(arr[0]);
    std::set<int> x;
    int prefix_sum = 0;
    for(int i =0;i<n;i++){
        prefix_sum += arr[i];
        x.insert(prefix_sum);

     if(prefix_sum == 0)  return true;
    }  
    if(x.size() != n){
        return true;
     
    }
    return false;
}