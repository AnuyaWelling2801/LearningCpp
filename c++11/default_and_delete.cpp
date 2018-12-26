//
//  default_and_delete.cpp
//  
//
//  Created by Anuya Welling on 12/20/18.
//

#include <iostream>
using namespace std;

class Test{
    int id{28};
    string name{"anuya"};
public:
    //default is the new keyword - uses the default values assigned
    Test() = default;
    Test(int id) : id(id){
    }
    //copy constructor default
    Test(const Test &other) = default;
    //usind default implementation of =
    Test &operator=(const Test &other) = delete;
    void print(){
        cout<<id<<":"<<name<<endl;
    }
    
};
int main(){
    
    Test anuya;
    anuya.print();
    
    Test atul(10);
    atul.print();
    
    //copy ininitialization, invokes copy constructor
    //wont work if copy constructor is set to delete instead of default
    Test test2 = anuya;
    
    //using = sign
    //cannot use since default implementation of = is deleted
    test2 = atul;
    return 0;
}
