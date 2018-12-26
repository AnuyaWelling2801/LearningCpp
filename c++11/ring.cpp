//
//  ring.cpp
//  
//
//  Created by Anuya Welling on 12/18/18.
//

#include <iostream>
#include "ring.h"
using namespace std;

int main(){
    ring<string> textring(3);
    
    textring.add("one");
    textring.add("teo");
    textring.add("three");
    textring.add("four");
    
    
    
    for(ring<string>::iterator it=textring.begin();it!=textring.end(); it++ ){
        cout << *it << "  ";
    }
    cout<<endl;
    //if the above for loop is implemented successfully, we can implement this for loop
    for(string value : textring){
        cout << value << "  ";
    }
    return 0;
}
