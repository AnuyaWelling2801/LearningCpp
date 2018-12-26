//
//  nested_templates.cpp
//  
//
//  Created by Anuya Welling on 12/17/18.
//

#include <iostream>
#include "ring.h"
using namespace std;


int main(){
    ring<string> textring(3);
    
    textring.add("one");
    textring.add("two");
    textring.add("three");
    textring.add("four");
    
    for(int i=0;i<textring.size();i++){
        cout<<textring.get(i)<<endl;
    }
}
