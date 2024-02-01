#include <iostream>
#include <unordered_map>
// cal lon sub[] where count of 0's = 1's

int main(){
    int arr[] = {0,0,1,0,1,0,1,1,1,0,1,0,0,1,0,0};
    int n = sizeof(arr)/sizeof(arr[0]);

    for(int i=0;i<n;i++){
        if(arr[i] == 0) arr[i] = -1;
    }
    std::unordered_map<int, std::pair<int, int>> x;

     x.insert({0, {-1,-1}});
    int prefix_sum = 0;

   for(int i=0; i<n; i++){
    prefix_sum += arr[i];

     if(x.find(prefix_sum) != x.end()){  //  if there is dublicate in prefix_sum
        x[prefix_sum].second = i; 
     }  
   else{
    x.insert({prefix_sum, {i,i}});
   }
   }
      
      int max_range = 0;
   for(auto it = x.begin(); it != x.end(); ++it){
      std::pair<int, int> y = it->second;   // it->second, you are accessing the std::pair<int, int> part of the key-value pair
      int range = y.second - y.first;
       max_range = std::max(max_range, range);
   }
   std::cout << max_range << std::endl;

   return 0;
}