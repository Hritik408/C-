#include <iostream>
#include <unordered_map>

int main(){
    int arr[] = {3,2,2,-1,-2,3,-4,3,-1,3,-2,1,3};
    int n = sizeof(arr)/sizeof(arr[0]);
    std::unordered_map<int, std::pair<int, int>> x;
    x.insert({0, {-1,-1}});
    int prefix_sum = 0;

   for(int i=0; i<n; i++){
    prefix_sum += arr[i];
 //   x.insert({prefix_sum, {i,i}});

     if(x.find(prefix_sum) != x.end()){
        x[prefix_sum].second++; 
     }
   else{
    x.insert({prefix_sum, {i,i}});
   }
   }
      
      int max_range = 0;
   for(auto it = x.begin(); it != x.size(); it++){
      std::pair<int,int> y = *it;
      int range = y.second - y.first;
      int max_range = std::max(max_range, range);
   }
   std::cout << max_range << std::endl;

   return 0;
}
