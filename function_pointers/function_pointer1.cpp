//
//  function_pointer1.cpp
//  
//
//  Created by Anuya Welling on 12/11/18.
//

#include <iostream>
using namespace std;

void test(string name){
    cout << "hello " << name <<endl;
}

int main(){
    void (*ptest)(string) = test;
    ptest("anuya");
    
    return 0;
}
