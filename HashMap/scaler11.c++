#include <iostream>
#include <unordered_set> 
// find longest sequence that can be rearranged in a strictly increasing order by 1.

int main(){
    int arr[] = {6,7,10,11,12};
    int n = sizeof(arr)/sizeof(arr[0]);
   
   std::unordered_set<int> s;

   for(int i = 0; i < n; i++){
      s.insert(arr[i]);
   }

   int ans = 0;
   for(auto it = s.begin(); it != s.end(); ++it){
      int x = * it;
      if(s.find(x-1) == s.end()){  // if x-1 is not present in set, then x is the starting point 
         int temp = x + 1;
         int count = 1;
         while(s.find(temp) != s.end()){ // continues as long as the consecutive element temp is found in the set s.
            count++;
            temp++;
         }
         ans = std::max(ans, count);
      }
   }

   std::cout<< ans ;

   return 0;
}