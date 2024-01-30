#include <iostream>
#include <queue>

int main(){
    std::queue<int> que;
    int n = 9;
    int count = 0;
    if(n==1) cout<< 1;
    if(n==2) cout<< 2;
    String x = que.front();
    String y = x;
    x += '1';
    while(count!=n){
    que.push(x);
    que.push(y + '2');
    que.pop();
    count++;
} 
    cout<< que.front() ;
}