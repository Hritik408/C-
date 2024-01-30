#include <iostream>
#include <string>

bool isvowel(char x){
         if (x == 'a' || x == 'e' || x == 'i' || x == 'o' || x == 'u' || x == 'A' ||x == 'E' || x == 'I' || x == 'O' || x == 'U'){
             return true;
         }
        return false;

    }

int main(){
    std::string input = "hello";  // hll
    int p1 = 0;
    while(p1 < input.size()){
        if(isvowel(input[p1])){  
            input.erase(p1, 1);  // if it is vowel then erase and p1 not inc but the next character come to currect index and if it is not vowel then p1 inc
        }
        else{
            p1++;
        }
    }

    std::cout << input << std::endl;
          
          return 0;
  
}