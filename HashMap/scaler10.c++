#include <iostream>
#include <unordered_map>
// cal dist elem in every window of size = k;

int main(){
    int arr[] = {2, 4, 3, 8, 3, 9, 4, 9, 4, 10};
     int n = sizeof(arr) / sizeof(arr[0]);
     int k = 4;

     std::unordered_map<int,int> x;

     for(int i = 0; i < k; i++){
        if(x.find(arr[i]) != x.end()){
            x[arr[i]]++;
        }
        else{
            x[arr[i]] = 1;
        }
     }
     std::cout<< x.size() << " ";

     for(int i = k; i < n; i++)
     {
        x[arr[i-k]]--;

        if(x[arr[i-k]] == 0){
            x.erase(arr[i-k]);
        }

        if(x.find(arr[i]) != x.end()){
       x[arr[i]]++;
        }

        else{
            x[arr[i]] = 1;
        }

        std::cout<< x.size() << " ";
     }

     return 0;

}



