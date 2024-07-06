#include <iostream>
#include <unordered_map>

int main(){
   std::unordered_map<std::string, int> m1;
   m1.insert({"india", 30});
   m1.insert({"china", 45});
   m1["india"] = 40;
   
   std::cout<< m1["india"] <<std::endl;

   return 0;
}