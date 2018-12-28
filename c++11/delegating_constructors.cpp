//
//  delegating_constructors.cpp
//  
//
//  Created by Anuya Welling on 12/26/18.
//

#include <iostream>
using namespace std;


class Parent{
    int dogs{5};
    string text{"hello"};
public:
    
    //this is delegating the constructor to call the parameterized constructor
    Parent() : Parent("hello") {
        cout << "no parameter string constructor " <<endl ;
    }
    
    Parent(string text){
        cout << text << " - is the parameter string constructor " << endl;
    }
};

class Child : public Parent{
public:
    //the default constructor now calls both the paremeterized and default constructors of the Parent class
    Child() = default;
};

int main(){
    
    //this also calls the parameterized constructor first and then the default constructor
    Parent p1;
    Parent p("hi");
    Child c;
    return 0;
}
