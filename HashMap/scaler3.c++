#include <iostream>
#include <unordered_map>
// find no of unique elements.

int main(){
    int arr[] = {3,4,5,3,7,4};
    int n = sizeof(arr)/sizeof(arr[0]);
    std::unordered_map<int, int> x;
    
    for(int i=0; i<n; i++){
        if(x.find(arr[i]) != x.end()){
            x[arr[i]]++;
        }
        else{
            x[arr[i]] = 1;
        }
    }

    int count = 0;
    for(auto it = x.begin(); it != x.end(); it++){
        std::pair<int, int> y = * it;
       // if(x[y.first] == 1)  count++;
       if(y.second == 1) {
        count++;
        std::cout << y.first << " ";
       }

    }
     std::cout << std::endl;

    std::cout<< "Number of unique elements are: " << count;
}