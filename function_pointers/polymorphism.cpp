//
//  polymorphism.cpp
//  
//
//  Created by Anuya Welling on 12/11/18.
//

#include <iostream>
using namespace std;

class Parent{
public:
    Parent(){
        
    }
    Parent(const Parent &other){
        cout << "copy constructor for parent" << endl;
    }
    virtual void print(){
        cout << "parent class" << endl;
    }
    
    virtual ~Parent(){
        
    }
};

class child : public Parent{
public:
    void print(){
        cout << "child class" <<endl;
    }
};

int main(){
    // try this with and without virtual for parent's void
    child c1;
    Parent &p1 = c1;
    p1.print();
    
    //invoking parent class' copy constructor. Object slicing
    Parent p2 = child();
    p2.print();
    return 0;
}
