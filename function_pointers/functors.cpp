//
//  functors.cpp
//  
//
//  Created by Anuya Welling on 12/11/18.
//

#include <iostream>
using namespace std;

struct Test{
    virtual bool operator()(string &text) = 0;
    
    virtual ~Test(){};
};

struct MatchTest: public Test{
    //functor overloads the () operator
    bool operator()(string &text){
        return text=="lion";
    }
};

//can pass around like a function/object
void check(string text, Test &test){
    if(test(text)){
        cout<<"text matches"<<endl;
    }
    else{
        cout<<"no match"<<endl;
    }
}

int main(){
    
    MatchTest func;
    string value = "lion";
    
    cout << func(value) <<endl;
    check("lion",func);
    return 0;
}
