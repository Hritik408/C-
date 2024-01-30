#include <iostream>
#include <string>

  std::string  reverse(std::string& st, int s, int e){

    // if(st.size() > 0)   return ;
    // if(e==0)   return NULL;

    if(s>=e)  return st;

    std::swap(const_cast<char&>(st[s]), const_cast<char&>(st[e]));

    return reverse(st, s+1, e-1);

 //   return st[e] + reverse(st,s,e-1);
  }

int main(){
    std::string st = "hello";
    int e = static_cast<int>(st.size()) - 1;
    int s = 0;
    std::string result =  reverse(st,s,e);
    std::cout << result <<std::endl;

    return 0;

}



