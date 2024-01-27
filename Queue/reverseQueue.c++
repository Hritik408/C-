#include <iostream>
#include <queue>
#include <stack>

   void reverse(std::queue<int>& q){
     std::stack<int> s;

     while(!q.empty()){
        s.push(q.front());
        q.pop();
     }

     while(!s.empty()){
        q.push(s.top());
        s.pop();
     }

   }

int main(){
    std::queue<int> que;
    int n;
    std::cout<< "enter no of element: ";
    std::cin>> n;
    for(int i= 0;i<n;++i){
        int m;
        std::cin>> m;
        que.push(m);
    }

    reverse(que);

      while(!que.empty()){
        std::cout<< que.front() << " ";
        que.pop();
    }
        std::cout << std::endl;
        
    return 0;
}