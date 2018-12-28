//
//  bind.cpp
//  
//
//  Created by Anuya Welling on 12/28/18.
//
//bind allows to create aliases to functions
#include <iostream>
using namespace std;
using namespace placeholders;

int add(int a, int b, int c){
    cout<<a<<","<<b<<","<<c<<endl;
    return a+b+c;
}

class Test{
public:
    int add(int a, int b, int c){
        cout<<a<<","<<b<<","<<c<<endl;
        return a+b+c;
    }
};

static int add1(int a, int b, int c){
    cout<<a<<","<<b<<","<<c<<endl;
    return a+b+c;
}


int main(){
    
    cout << add(1,2,3) <<endl;
    //call bind with the same arguements everytime
    auto calculator = bind(add,1,2,3);
    cout << calculator() << endl;

    //use placeholders to call add
    //each placeholder _N is replaced by the corresponding Nth unbound argument.
    auto calculate = bind(add,_2,_1,_3);
    cout << calculate(1,2,3) << endl;
    
    //can use a combination of hardcoded values and placeholders
    auto calculate1 = bind(add,_2,100,_1);
    cout << calculate1(1,2) << endl;
    
    //bind to a member function
    Test test;
    auto calculate_test = bind(&Test::add,test, _2, 100, _1);
    cout << calculate1(1,2) << endl;
    
    //bind to a static method
    auto calculate_static = bind(add,_2,_1,_3);
    cout << calculate(1,2,300) << endl;
    

    return 0;
}
