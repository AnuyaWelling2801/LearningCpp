//
//  rvalue_references.cpp
//  
//
//  Created by Anuya Welling on 12/26/18.
//

#include <iostream>
using namespace std;

class Test{
public:
    Test(){
        cout<<"this is a test class"<<endl;
    }
};
//without compiler optimizations, the function produces a temporary value which is copied and goes out of scope.
Test gettest(){
    return Test();
}

void check(const Test &lvalue){
    cout<<"this is an lvalue reference"<<endl;
}
void check(Test &&rvalue){
    cout<<"this is an rvalue reference"<<endl;
}
int main(){
  
    int value1 = 7;
    //this works, because pointer is to the LValue
    int *pValue = &value1;
    //this does not work because pointer is to the RValue
    //RValues are often temporary values
    //int *pValue2 = &7;
    
    //increment and use value2
    //this works. Here the number is incremented and stored in value1, hence its a LValue
    int *pValue3 = &++value1;
    cout << *pValue3 <<endl;
    
    //the post increment does not work. Here a temporary variable is created. hence its an RValue
    //int pValue4 = &value1++
    
    //Here value1 is converted to an rvalue when 7 is added to it. Hence & cannot be used with it
    //int *s = &(7 + value1)
    
    //This is normal and similar is used in c++98
    //on-const lvalue reference to type 'Test' cannot bind to a temporary of type 'Test' <--- error generated
    Test test1 = gettest();
    Test &lTest = test1;
    
    //This doesnt work
    //Test &rTest1 = gettest();
    
    //BUT const lvalue references can bind to rvalues
    //This happens because the lifetime of the rvalue gets extended
    const Test &ctest = gettest();
    
    //&& rvalue reference is denoted by &&
    //rvalue pointing  to an lvalue produces an error - rvalue reference to type 'Test' cannot bind to lvalue of type 'Test'
    //Test &&rvalue = test1;
    
    Test &&ravlue = gettest();
    
    //lvalue
    check(test1);
    //rvalue
    check(gettest());
    check(Test());
};
