#include <iostream>
#include <string>

bool palindrome(const std::string S, int s, int e){
    if(s >= e)  return true;

    if(S[s] == S[e]){
      return  palindrome(S, s + 1, e - 1);
    }
    return false;
}

int main(){
    std::string S = "abcdcba";
    
    int s = 0;
  //  std::size_t e = static_cast<int>(S.size()) - 1;
      int e = static_cast<int>(S.size()) - 1;

    std::cout<< std::boolalpha << palindrome(S, s, e) << std::endl;

    return 0;
}