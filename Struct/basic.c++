#include <bits/stdc++.h>

using namespace std;

struct person
{
    string name;
    int age;
    char gender;

    void print(){
        cout << name << " " << age << " " << gender << endl;
    } 

    void input(string name1, int age1, char gender1){
        name = name1;
        age = age1;
        gender = gender1;
    }
};

int main(){
    person p;
    p.input("hritik",22,'M');
    p.print();

    person *ptr = &p;
    ptr->print();
    cout << (ptr->name) << endl;
    return 0;
}


