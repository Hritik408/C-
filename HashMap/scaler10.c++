#include <iostream>
#include <set>
#include <unordered_map>
// cal dist elem in every window of size = k;

int main(){
    int arr[] = {2, 4, 3, 8, 3, 9, 4, 9, 4, 10};
     int n = sizeof(arr) / sizeof(arr[0]);
     int k = 4;

     std::unordered_map<int,int> m;

     for(int i = 0; i < k; i++){
        if(m.find(arr[i]) != m.end()){
            m[arr[i]]++;
        }
        else{
            m[arr[i]] = 1;
        }
     }
     std::cout<< m.size() << " ";

     for(int i = k; i < n; i++)
     {
        m[arr[i-k]]--;

        if(m[arr[i-k]] == 0){
            m.erase(arr[i-k]);
        }

        if(m.find(arr[i]) != m.end()){
       m[arr[i]]++;
        }

        else{
            m[arr[i]] = 1;
        }

        std::cout<< m.size() << " ";
     }

     return 0;

}



