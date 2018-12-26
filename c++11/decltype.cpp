//
//  decltype.cpp
//  
//
//  Created by Anuya Welling on 12/17/18.
//

#include <iostream>
#include <typeinfo>   //to use typeid
using namespace std;

//use -std=c++11 -std=gnu++11
int main(){
    string value;
    cout << typeid(value).name() <<endl;  //uses name mangling in case of strings
     //decltype copies the typename
    
    decltype(value) name = "anuya";
    cout << typeid(name).name() <<endl;
    cout<<name<<endl;
}
