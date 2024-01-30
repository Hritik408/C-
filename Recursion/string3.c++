#include <iostream>
#include <algorithm>
#include <sstream>
#include <vector>

int main(){
   std::string s = "Let's take LeetCode contest";
 //   "s'teL ekat edoCteeL tsetnoc"
   std::reverse(s.begin(), s.end());

        std::stringstream ss(s);
        std::vector<std::string> words;
        std::string word;

        while(ss >> word){
            words.push_back(word);
        }

        std::reverse(words.begin(), words.end());

        std::string result;
        for(const auto& k : words){
            result += k + " ";
        }

        result.pop_back();

        std::cout << result << std::endl;
    
    return 0;
}