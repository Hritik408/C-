#include <iostream>

int main(){
    dequeue <int> dq;
    for(int i =0;i<k;i++){
       while(dq.size()>0 && dq.rear()<arr[i]){
        dq.pop_rear();
       } 
       dq.push_rear(arr[i]);
    }   
    std::cout << dq.front() << std::endl;

    for(int i=k;i<n;i++){
        while(dq.size()>0 && dq.rear()<arr[i]){
            dq.pop_rear();
        }
        dq.push_rear(arr[i]);
      
      if(dq.front() == arr[i-k]){
        dq.pop_front();
      }
    std::cout << dq.front << std::endl:
    }

    return 0;
}