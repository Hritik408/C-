#include <iostream>
#include <unordered_map>
// find freq of given query(Q)

int main(){
    int arr[] = {9,8,1,10,1,8,6,4,2,6,9,6};
    int n = sizeof(arr)/sizeof(arr[0]);

    std::unordered_map<int, int> freq;

    for(int i=0; i<n; i++){
        if(freq.find(arr[i]) != freq.end()){
            freq[arr[i]]++;
        }
        else{
            freq[arr[i]] = 1;
        }
    }

       int q;
       std::cout << "enter number of queries: ";
       std::cin>> q;
       
    while (q--)
    {
        int x;
        std::cout<< "enter query element: ";
        std::cin>> x;

        if(freq.find(x) != freq.end()){
            std::cout << freq[x] <<std::endl;
        }
        else{
            std::cout<< x << " is not found " <<std::endl;
        }
    }
      return 0;
} 