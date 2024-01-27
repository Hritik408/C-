#include <iostream>
#include <queue>

int main(){
    std::queue<int> myQueue;
    
    int n;
    std::cout<< "enter no of element: ";
    std::cin>> n;
    for(int i= 0;i<n;++i){
        int element;
      std::cin>> element;
      myQueue.push(element);
    }  

while (!myQueue.empty())
    {
    std::cout<< myQueue.front() << " ";
        myQueue.pop();
    }
    return 0;
}