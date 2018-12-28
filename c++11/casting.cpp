//
//  casting.cpp
//  
//
//  Created by Anuya Welling on 12/28/18.
//

#include <iostream>
using namespace std;

class Parent{

    virtual void speak(){
        cout << "parent" <<endl;
    }
};

class Brother : public Parent{
    
};

class Sister : public Parent{
    
};

int main(){
    //static casts
    float value = 3.23;
    //creating a new integer
    cout << (int)value << endl;
    cout << static_cast<int> (value) <<endl;
    
    //Parent parent;
    Brother brother;
    Sister sister;
    
    //STATIC CASTS
    //done at compile time
    //Works due to polymorphism
    Parent *pp = &brother;
    
    //This works but usually avoid this
    //sBrother *pb = static_cast<Brother *>(&parent);
    
    //Static cast is dangerous but can be used
    Parent *ppb = &brother;
    Brother *pbb = static_cast<Brother *>(ppb);
    
    //Static casts can be used to convert rvalue references to lvalue references
    //Parent &&p = static_cast<Parent &>(parent);
    
    //DYNAMIC CLASS
    //check if rtti is turned on the the compiler. Default for GNU. RTTI = Run Time Type Information
    //Dynamic class is better since it does runtime checking
    Brother *pbb_dynamic = dynamic_cast<Brother *>(ppb);
    if(pbb_dynamic == nullptr){
        cout << "Invalid cast " <<endl;
    }
    else{
        cout << pbb << endl;
    }
    
    //REINTERPRET CAST
    Parent *pbb_reinterpret = &brother;
    
    //dynamic casting from a sister pointer to a brother is invalid
    Sister *sbb_dynamic = dynamic_cast<Sister *>(pbb_reinterpret);
    if(sbb_dynamic == nullptr){
        cout << "Invalid cast " <<endl;
    }
    else{
        cout << pbb << endl;
    }
    
    //with reinterpret cast, you can cast one thing to another without any checking
    Sister *sbb_reinterpret = reinterpret_cast<Sister *>(pbb_reinterpret);
    
    
    
    return 0;
}
