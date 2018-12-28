//
//  mutable_lambda.cpp
//  
//
//  Created by Anuya Welling on 12/26/18.
//

#include <iostream>
using namespace std;

int main(){
    
    int cats=5;
    
    //the local value of cats is changed but not the one outside lambda
    //the variable is still passed by value. Hence the copy is changed
    //gives an error without the keywork mutable
    
    [cats]() mutable{
        cats = 8;
        cout << cats <<endl;
    }();
    
    cout << cats <<endl;
    return 0;
}
