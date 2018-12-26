//
//  enhanced_for_loop.cpp
//  
//
//  Created by Anuya Welling on 12/17/18.
//
// To run this - g++ -Wall -fexceptions -std=c++11 -fPIC auto.cpp

#include <iostream>
using namespace std;

int main(){
    
    auto texts = {"one", "two", "three"};
    //similar to python
    for (auto text : texts){
        cout << text << endl;
    }
    
    //Use similarly for vectors or string(to print one character at a time)
    return 0;
}
