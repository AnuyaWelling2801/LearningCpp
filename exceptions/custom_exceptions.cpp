//
//  custom_exceptions.cpp
//  
//
//  Created by Anuya Welling on 12/3/18.
//
#include <iostream>
using namespace std;

class MyExeption: public exception{
public:
    virtual const char* what() const throw() {
        return "Something bad happened";
    }
};

class Test{
    public:
    void goesWrong(){
        throw MyExeption();
    }
};

int main(){
    Test test;
    try{
            test.goesWrong();
    }
    catch(MyExeption &e){
        std::cout<<e.what()<<std::endl;
    }
    
    return 0;
}

