#include <iostream>
#include <queue>
#include <stack>   

   void reverse(std::queue<int>& q, int k){
     std::stack<int> s;
     int size = q.size();
    
    for(int i =0;i<k;++i){
        s.push(q.front());
        q.pop();
    }   

    for(int i =0;i<k;++i){
        q.push(s.top());
        s.pop();
    } 

    for(int i = k;i<size;++i){
        q.push(q.front());
        q.pop();
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
    int k = 4;

    reverse(que,k);

      while(!que.empty()){
        std::cout<< que.front() << " ";
        que.pop();
    }
        std::cout << std::endl;
        
    return 0;
}