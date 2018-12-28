//
//  perfect_forwarding.cpp
//  
//
//  Created by Anuya Welling on 12/28/18.
//

#include <iostream>
using namespace std;

class Test{
    
};

//arg will get passed as an rvalue or lvalue depending on the type of typename and the rules of reference collapsing will apply incase you dont do forwarding
template<typename T>
void call(T &&arg){
    //check(arg);
    //check(static_cast<T>(arg));
    //instead of static casts use forward. does the same thing
    check(forward<T>(arg));
}
void check(Test &test){
    cout<<"this is a lvalue reference" <<endl;
}

void check(Test &&test){
    cout<<"this is a rvalue reference" <<endl;
}
int main(){
    
    Test test;
    //reference collapsing rules
    //If auto boiled down to an lvalue reference type, the reference as a whole would collapse and it would boil down to an lvalue reference
    auto &&t = test;
    
    //rvalue passed but we get the lvalue as the answer. hence we haven't got perfect forwarding. This is with the commented code
    //with the uncommented code, rvalue is passed and we get the answer as the rvalue.
    call(Test());
    call(test);
    
    
    return 0;
}
