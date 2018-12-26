//
//  lambda.cpp
//  
//
//  Created by Anuya Welling on 12/22/18.
//

#include <iostream>
using namespace std;

void Test(void (*pFunc)()){
    pFunc();
}

void runDivide(double (*divide)(double a,double b)){
    cout << divide(9,3) << endl;
}

class lamda{
private:
    int one{1};
    int two{2};
    
public:
    void run(){
        //this is always passed by reference
        auto pRun = [this](){cout << one << two << endl;};
        pRun();
    }
};

int main(){
    
    //basic lambda code. Doesnt do anything
    //[](){};
    //func is a functor
    auto func = [](){cout<<"Simple function with no name"<<endl;};
    func();
    //We can also pass it around like functors
    Test(func);
    //can pass lambda directly
    Test([](){cout<<"Simple function with no name 2"<<endl;});
    
    //pass a parameter and return a value
    //uses trailing return type
    auto pDivide = [](double a, double b) -> double{
        if(b==0.0){
            return 0;
        }
        return a/b;
    };
    
    cout << pDivide(10.5,5.5) << endl;
    runDivide(pDivide);
    
    //lambda captures
    int one=1;
    int two=2;
    int three=3;
    [one](){cout<<"this is "<< one <<endl;}();
    
    //capture all local variables by values
    [=](){cout << "this is " << one << two << three <<endl ;}();
    
    //capture all local variables by reference
    [&](){one = 8; two = 7; cout << "this is " << one << two << three <<endl ;}();
    
    //capture all local references by value and three by reference
    [=, &three](){three= 5; cout << "this is " << one << two << three<<endl;}();
    
    //all values are changed
    cout <<"this is "<< one <<two <<three << endl;
    
    //for classes and objects
    lamda L;
    L.run();
}
